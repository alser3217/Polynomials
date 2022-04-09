/*#ifndef __TREE_TABLE__
#define __TREE_TABLE__

#include "base_table.hxx"

namespace Tables {
	class Node {
		Data data;
		Data* pLeft;
		Data* pRight;
		int height;
	public :
		Node (Data _data = Data(), Data* _pLeft = nullptr, Data* _pRight = nullptr, int _height = 1) : data(_data), pLeft(_pLeft), pRight(_pRight), height(_height) {}
	};

	class TreeTable : public BaseTable {
		Node* pHead;
	private:
		Node* rightRotate(Node* _pRoot);
		Node* leftRotate(Node* _pRoot);

	public:
		TreeTable(Node* _pHead = nullptr) {}

	};
}


#endif
*/
