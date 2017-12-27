/*
	已知二叉树的先序和中序遍历序列，求出二叉树。
*/

/*
	解法：
	假设有一个如下所示的二叉树
	    A
	   /  \
	  B    C
	 / \  / \
	D  E  F  G
	先序遍历 pre_order 为 ABDECFG
	中序遍历 in_order 为 DBEAFCG
	显然可见，根节点为 A，也即 pre_order 的第一个元素。
	pre_order 中的剩余元素都是 A 的后代节点。
	显然可见，在 in_order 中，位于 A 之前的是根节点的左子树节点，并且这一连续序列是左子树的中序遍历；位于 A 之后的是根节点的右子树节点，并且这一连续序列是右子树的中序遍历。
	假设左子树中序遍历的元素个数是 l_num，右子树中序遍历的元素个数是 r_num，
	又可见，在 pre_order 中，从 A 往后的 l_num 个连续序列是左子树的先序遍历，再之后的 r_num 个连续序列是右子树的先序遍历。
	于是可以获得左/右子树的先序和中序序列。便可以分别获得左子树和右子树的根节点。
	由此递归，便可获得二叉树的所有节点。
*/

#include <vector>

// 二叉树节点的数据结构
struct Node {
	Node() : ch(0), left_child(nullptr), right_child(nullptr) {}
	Node(char val) : ch(val), left_child(nullptr), right_child(nullptr) {}
	~Node();
	char ch;
	Node* left_child;
	Node* right_child;
};

Node::~Node() {
	if (left_child) {
		delete left_child;
		left_child = nullptr;
	}
	if (right_child) {
		delete right_child;
		right_child = nullptr;
	}
}

Node* GetTree(const std::vector<char>& pre_order, const std::vector<char>& in_order) {
	if (pre_order.empty()) // 如果遍历序列为空，则返回空节点
		return nullptr;
	Node* node = new Node(pre_order.front()); // 获取根节点
	size_t i = 0;
	for (; i < in_order.size(); ++i) { // 在 in_order 中找到根节点的下标
		if (in_order[i] == pre_order.front())
			break;
	}

	// 递归，获取子树的根节点，以及子树的子树的根节点，以此往下，直到序列为空为止
	node->left_child = GetTree(std::vector<char>(pre_order.begin() + 1, pre_order.begin() + 1 + i),
							   std::vector<char>(in_order.begin(), in_order.begin() + i));
	node->right_child = GetTree(std::vector<char>(pre_order.begin() + 1 + i, pre_order.end()),
								std::vector<char>(in_order.begin() + i + 1, in_order.end()));
	return node;
}

int test() {
	std::vector<char> pre_order = { 'A', 'B', 'D', 'E', 'C', 'F', 'G' };
	std::vector<char> in_order = { 'D', 'B', 'E', 'A', 'F', 'C', 'G' };
	Node* tree = GetTree(pre_order, in_order);
	Node* tree2 = GetTree({ 'A', 'B', 'C', 'D', 'E', 'G', 'F' },
						  { 'C', 'B', 'E', 'G', 'D', 'F', 'A' });
	delete tree;
	delete tree2;
	return 0;
}

int main() {
	test();
	return 0;
}