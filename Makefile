CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
DEBUG = -g
HEADER = binary_trees.h
PRINT = binary_tree_print.c

all: t0 t1 t2 t3 t4 t5 t6 t7 t8 t9 t10 t11 t12 t13 t14 t15 t16 t17 t18 t19 t20 t21 t22 t23 t24 t25 t26 t27 t28 t30 t31 t32 t33 t34 t36 t37 t38 t39 t40

betty_all:
	betty $(HEADER) $$(ls *.c | grep -v main.c)

t0:
	$(CC) $(CFLAGS) $(PRINT) 0-main.c 0-binary_tree_node.c -o 0-node $(DEBUG)
t1:
	$(CC) $(CFLAGS) $(PRINT) 1-main.c 1-binary_tree_insert_left.c 0-binary_tree_node.c -o 1-left $(DEBUG)
t2:
	$(CC) $(CFLAGS) $(PRINT) 2-main.c 2-binary_tree_insert_right.c 0-binary_tree_node.c -o 2-right $(DEBUG)
t3:
	$(CC) $(CFLAGS) $(PRINT) 3-main.c 3-binary_tree_delete.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 3-del $(DEBUG)
t4:
	$(CC) $(CFLAGS) $(PRINT) 4-main.c 4-binary_tree_is_leaf.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 4-leaf $(DEBUG)
t5:
	$(CC) $(CFLAGS) $(PRINT) 5-main.c 5-binary_tree_is_root.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 5-root $(DEBUG)
t6:
	$(CC) $(CGLAGS) $(PRINT) 6-main.c 6-binary_tree_preorder.c 0-binary_tree_node.c -o 6-pre $(DEBUG)
t7:
	$(CC) $(CFLAGS) $(PRINT) 7-main.c 7-binary_tree_inorder.c 0-binary_tree_node.c -o 7-in $(DEBUG)
t8:
	$(CC) $(CFLAGS) $(PRINT) 8-main.c 8-binary_tree_postorder.c 0-binary_tree_node.c -o 8-post $(DEBUG)
t9:
	$(CC) $(CFLAGS) $(PRINT) 9-main.c 9-binary_tree_height.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 9-height $(DEBUG)
t10:
	$(CC) $(CFLAGS) $(PRINT) 10-main.c 10-binary_tree_depth.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 10-depth $(DEBUG)
t11:
	$(CC) $(CFLAGS) $(PRINT) 11-main.c 11-binary_tree_size.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 11-size $(DEBUG)
t12:
	$(CC) $(CFLAGS) $(PRINT) 12-main.c 12-binary_tree_leaves.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 12-leaves $(DEBUG)
t13:
	$(CC) $(CFLAGS) $(PRINT) 13-main.c 13-binary_tree_nodes.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 13-nodes $(DEBUG)
t14:
	$(CC) $(CFLAGS) $(PRINT) 14-main.c 14-binary_tree_balance.c 0-binary_tree_node.c 2-binary_tree_insert_right.c 1-binary_tree_insert_left.c -o 14-balance $(DEBUG)
t15:
	$(CC) $(CFLAGS) $(PRINT) 15-main.c 15-binary_tree_is_full.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 15-full $(DEBUG)
t16:
	$(CC) $(CFLAGS) $(PRINT) 16-main.c 16-binary_tree_is_perfect.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 16-perfect $(DEBUG)
t17:
	$(CC) $(CFLAGS) $(PRINT) 17-main.c 17-binary_tree_sibling.c 0-binary_tree_node.c -o 17-sibling $(DEBUG)
t18:
	$(CC) $(CFLAGS) $(PRINT) 18-main.c 18-binary_tree_uncle.c 0-binary_tree_node.c -o 18-uncle $(DEBUG)
t100:
	$(CC) $(CFLAGS) $(PRINT) 100-main.c 100-binary_trees_ancestor.c 0-binary_tree_node.c -o 100-ancestor $(DEBUG)
t101:
	$(CC) $(CFLAGS) $(PRINT) 101-main.c 101-binary_tree_levelorder.c 0-binary_tree_node.c 3-binary_tree_delete.c -o 101-lvl $(DEBUG)
t102:
	$(CC) $(CFLAGS) $(PRINT) 102-main.c 102-binary_tree_is_complete.c 0-binary_tree_node.c 3-binary_tree_delete.c -o 102-complete $(DEBUG)
t103:
	$(CC) $(CFLAGS) $(PRINT) 103-binary_tree_rotate_left.c 103-main.c 0-binary_tree_node.c -o 103-rotl $(DEBUG)
t104:
	$(CC) $(CFLAGS) $(PRINT) 104-binary_tree_rotate_right.c 104-main.c 0-binary_tree_node.c -o 104-rotr $(DEBUG)
t110:
	$(CC) $(CFLAGS) $(PRINT) 110-main.c 110-binary_tree_is_bst.c 0-binary_tree_node.c -o 110-is_bst $(DEBUG)
t111:
	$(CC) $(CFLAGS) $(PRINT) 111-bst_insert.c 111-main.c 0-binary_tree_node.c -o 111-bst_insert $(DEBUG)
t112:
	$(CC) $(CFLAGS) $(PRINT) 112-array_to_bst.c 112-main.c 111-bst_insert.c 0-binary_tree_node.c -o 112-bst_array $(DEBUG)
t113:
	$(CC) $(CFLAGS) $(PRINT) 113-bst_search.c 113-main.c 112-array_to_bst.c 111-bst_insert.c 0-binary_tree_node.c -o 113-bst_search $(DEBUG)
t114:
	$(CC) $(CFLAGS) $(PRINT) 114-bst_remove.c 114-main.c 112-array_to_bst.c 111-bst_insert.c 0-binary_tree_node.c 3-binary_tree_delete.c -o 114-bst_rm $(DEBUG)
t120:
	$(CC) $(CFLAGS) $(PRINT) 120-main.c 120-binary_tree_is_avl.c 0-binary_tree_node.c -o 120-is_avl $(DEBUG)
t121:
	$(CC) $(CFLAGS) $(PRINT) 121-avl_insert.c 121-main.c 14-binary_tree_balance.c 103-binary_tree_rotate_left.c 104-binary_tree_rotate_right.c 0-binary_tree_node.c -o 121-avl_insert $(DEBUG)
t122:
	$(CC) $(CFLAGS) $(PRINT) 122-array_to_avl.c 122-main.c 121-avl_insert.c 0-binary_tree_node.c 14-binary_tree_balance.c 103-binary_tree_rotate_left.c 104-binary_tree_rotate_right.c -o 122-avl_array $(DEBUG)
t123:
	$(CC) $(CFLAGS) $(PRINT) 123-avl_remove.c 123-main.c 103-binary_tree_rotate_left.c 104-binary_tree_rotate_right.c 122-array_to_avl.c 121-avl_insert.c 14-binary_tree_balance.c 3-binary_tree_delete.c 0-binary_tree_node.c -o 123-avl_rm $(DEBUG)
t124:
	$(CC) $(CFLAGS) $(PRINT) 124-main.c 124-sorted_array_to_avl.c 0-binary_tree_node.c -o 124-avl_sorted $(DEBUG)
t130:
	$(CC) $(CFLAGS) $(PRINT) 130-main.c 130-binary_tree_is_heap.c 0-binary_tree_node.c -o 130-is_heap $(DEBUG)
t131:
	$(CC) $(CFLAGS) $(PRINT) 131-main.c 131-heap_insert.c 0-binary_tree_node.c -o 131-heap_insert $(DEBUG)
t132:
	$(CC) $(CFLAGS) $(PRINT) 132-main.c 132-array_to_heap.c 131-heap_insert.c 0-binary_tree_node.c -o 132-heap_array $(DEBUG)
t133:
	$(CC) $(CFLAGS) $(PRINT) 133-main.c 133-heap_extract.c 132-array_to_heap.c 131-heap_insert.c 3-binary_tree_delete.c -o 133-heap_extract $(DEBUG)
t134:
	$(CC) $(CFLAGS) $(PRINT) 134-main.c 134-heap_to_sorted_array.c 133-heap_extract.c 132-array_to_heap.c 131-heap_insert.c -o 134-heap_sort $(DEBUG)
