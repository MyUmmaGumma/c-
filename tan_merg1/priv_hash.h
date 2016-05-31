/*
 * priv_hash.h
 *
 * Pratap Pereira, March 2016
 * 
 * Based on trans_hash made not transactional -- I have seen it all.
 *
 * Copyright (c) 2016 by cisco Systems, Inc.
 * All rights reserved
 */


#ifndef __PRIV_HASH_H__
#define __PRIV_HASH_H__

/*
 * Macros that define a hash table 
 * 
 * The size passed in from tdl is the max number of elements
 * that will be inserted into the hash table.
 */

/* 
 * The multipe of max number of elements to make the 
 * actual hash table. 5 ==> fill factor of 20%
 */
#define HASH_MULTIPLE 5

#define HASH_SIZE(n) (hash_pow2_larger((n) * HASH_MULTIPLE))
#define HASH_MASK(n) (((n))-1)

#define HASHTABLE_STRUCT(name, type) 					\
struct name##ht { 							\
    LIST_HEAD(name##lh, type) ht;					\
};									\

#define HASH_HEAD(name, type)			\
    struct name {				\
	u_int32_t entries;			\
	u_int32_t hashsize;			\
	u_int32_t hashshift;			\
	struct name##ht *htable;		\
    }

#define HASH_INIT(root, size) do {					\
	{ 								\
	    u_int32_t hash_i;						\
	    (root)->hashsize=HASH_SIZE(size);				\
	    (root)->hashshift=hash_log2(HASH_SIZE(size));		\
	    for (hash_i=0; 						\
		 hash_i < HASH_SIZE(size);			 	\
		 hash_i++) {						\
		 LIST_INIT(&((root)->htable[hash_i].ht));		\
	    }								\
        }								\
    } while (0)

#define HASH_ENTRY(type)			\
    LIST_ENTRY(type)

#define HASH_NEXT_IN_BUCKET(elm, field)  LIST_NEXT(elm, field)
#define HASH_COUNT(head)		    ((head)->entries)
#define HASH_HT(head)		    ((head)->htable)
#define HASH_HT_BUCKET_HEAD(head, val)   &((HASH_HT((head)))[(val)].ht)
#define HASH_HT_BUCKET_FIRST(head, val)  LIST_FIRST(HASH_HT_BUCKET_HEAD(head, val))

/* Generates prototypes and inline functions */
#define HASH_PROTOTYPE(name, type, field, cmp, hashgen)   		\
    struct type *name##_HASH_REMOVE(struct name *, struct type *);	\
    struct type *name##_HASH_INSERT(struct name *, struct type *);	\
    struct type *name##_HASH_FIND(struct name *, struct type *);	\

#define HASH_GENERATE(name, type, field, cmp, hashgen)			\
    									\
    static u_int32_t name##_HASH_MOD(u_int32_t hsize, 			\
					u_int32_t hshift, 		\
					u_int32_t h) {			\
	u_int32_t rv = ((( ( (h) >> (hshift) )				\
			 ^ ( (h) & HASH_MASK((hsize))) )		\
			 & HASH_MASK((hsize))));			\
	return (rv);							\
    }									\
    									\
    /* Finds the node with the same key as elm */			\
    struct type *							\
    name##_HASH_FIND(struct name *head, struct type *elm)		\
    {									\
	u_int32_t hash_val;						\
	hash_val = name##_HASH_MOD(head->hashsize, head->hashshift,  	\
				      hashgen(elm));			\
	boolean found=FALSE;						\
	struct type *iter = HASH_HT_BUCKET_FIRST(head, hash_val);	\
	if (iter) {							\
	    found=TRUE;							\
	    /* bucket has entries */					\
	    while ( (cmp) ( (elm) , (iter) ) != 0 ) {			\
		iter=HASH_NEXT_IN_BUCKET(iter, field);			\
		if (iter == NULL) {					\
		    found=FALSE;					\
		    break;						\
		}							\
	    }								\
	}								\
	if (found) {							\
	    return iter;						\
	} else {							\
	    return NULL;						\
	}								\
    };									\
    									\
    struct type *							\
    name##_HASH_REMOVE(struct name *head __UNUSED, struct type *elm) 	\
    {									\
	LIST_REMOVE(elm, field);					\
	head->entries =  head->entries-1;				\
	return elm;							\
    }									\
    									\
    /* Inserts a node into the Hash table */				\
    struct type *							\
    name##_HASH_INSERT(struct name *head, struct type *elm)		\
    {									\
	u_int32_t hash_val;						\
	hash_val = name##_HASH_MOD(head->hashsize, head->hashshift,	\
				      hashgen(elm));			\
	boolean found=FALSE;						\
	struct type *iter = HASH_HT_BUCKET_FIRST(head, hash_val);	\
	if (iter) {							\
	    found=TRUE;							\
	    while ( (cmp) ( (elm) , (iter) ) != 0 ) {			\
		iter = HASH_NEXT_IN_BUCKET(iter, field);		\
		if (iter == NULL) {					\
		    found=FALSE;					\
		    break;						\
		}							\
	    }								\
	}								\
	if (found) {							\
	    return NULL;						\
	} else {							\
	    LIST_INSERT_HEAD(HASH_HT_BUCKET_HEAD(head, hash_val),	\
                                elm, field);				\
        head->entries = head->entries+1;				\
	}								\
	return elm;							\
    }

#define HASH_INSERT(name, x, y) \
    name##_HASH_INSERT(x, y)
#define HASH_REMOVE(name, x, y) \
    name##_HASH_REMOVE(x, y)
#define HASH_FIND(name, x, y) \
    name##_HASH_FIND(x, y)

#define HASH_FOREACH(type, head, field, cb, ctx)			\
    { u_int32_t ndx; 							\
	u_int32_t done = 0;						\
	for (ndx=0; ndx < (head)->hashsize; ndx++) {			\
	    struct type *iter = HASH_HT_BUCKET_FIRST(head, ndx);	\
	    while (iter) {						\
		/* bucket has entries */				\
		if (cb(iter, ctx) == FALSE) { done = 1; break; };	\
		iter=HASH_NEXT_IN_BUCKET(iter, field);			\
	    }								\
	    if (done) { break; };					\
	}								\
    }


#endif /*__PRIV_HASH_H__*/
