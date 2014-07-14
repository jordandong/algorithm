/* Sink Zero in Binary Tree. Swap zero value of a node with non-zero value of one of its descendants 
 * so that no node with value zero could be parent of node with non-zero.
 */

void sinkzero(Node& node, stack<int>& s) {
	if (node == null) return;
	if (node->val == 0) s.push(node);
	sinkzero(node->left, s);
	sinkzero(node->right, s);
	if (!s.empty()) {
		if (node->val != 0) swap(node->val, s.top()->val);
		s.pop(); // if node->val == 0 then s.top() must be this node
	}
}
