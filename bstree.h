//
//  bstree.h
//  Data Structure
//
//  Created by ryer on 5/11/15.
//  Copyright (c) 2015 ryer. All rights reserved.
//

#ifndef Data_Structure_bstree_h
#define Data_Structure_bstree_h

template <class T>
class BSTree {
public:
	BSTree();
	BSTree(const BSTree &rhs);
	~BSTree();
	
	bool contains(const T &x) const;
	const T &findMin() const;
	const T &findMax() const;
	void insert(const T &x);
	void remove(const T &x);
	bool empty() const;
	void makeEmpty();
	const BSTree &operator=(const BSTree &rhs);
	void print() const;
	
private:
	struct node {
		node(const T &e, node *l, node *r) : element(e), left(l), right(r) { }
		T element;
		node *left;
		node *right;
	};
	
	bool contains(const T &, node *n) const;
	node *findMin(node *n) const;
	node *findMax(node *n) const;
	void insert(const T &x, node *&n) const;
	void remove(const T &x, node *&n) const;
	void makeEmpty(node *&n);
	node *clone(node *n) const;
	void print(node *n) const;

private:
	node *root;
};

#endif
