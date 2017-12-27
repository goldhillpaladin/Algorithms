/*
	��֪�����������������������У������������
*/

/*
	�ⷨ��
	������һ��������ʾ�Ķ�����
	    A
	   /  \
	  B    C
	 / \  / \
	D  E  F  G
	������� pre_order Ϊ ABDECFG
	������� in_order Ϊ DBEAFCG
	��Ȼ�ɼ������ڵ�Ϊ A��Ҳ�� pre_order �ĵ�һ��Ԫ�ء�
	pre_order �е�ʣ��Ԫ�ض��� A �ĺ���ڵ㡣
	��Ȼ�ɼ����� in_order �У�λ�� A ֮ǰ���Ǹ��ڵ���������ڵ㣬������һ���������������������������λ�� A ֮����Ǹ��ڵ���������ڵ㣬������һ���������������������������
	�������������������Ԫ�ظ����� l_num�����������������Ԫ�ظ����� r_num��
	�ֿɼ����� pre_order �У��� A ����� l_num �������������������������������֮��� r_num �����������������������������
	���ǿ��Ի����/��������������������С�����Էֱ������������������ĸ��ڵ㡣
	�ɴ˵ݹ飬��ɻ�ö����������нڵ㡣
*/

#include <vector>

// �������ڵ�����ݽṹ
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
	if (pre_order.empty()) // �����������Ϊ�գ��򷵻ؿսڵ�
		return nullptr;
	Node* node = new Node(pre_order.front()); // ��ȡ���ڵ�
	size_t i = 0;
	for (; i < in_order.size(); ++i) { // �� in_order ���ҵ����ڵ���±�
		if (in_order[i] == pre_order.front())
			break;
	}

	// �ݹ飬��ȡ�����ĸ��ڵ㣬�Լ������������ĸ��ڵ㣬�Դ����£�ֱ������Ϊ��Ϊֹ
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