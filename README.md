# BinarySearchTree

A generic, header-only Binary Search Tree implemented in C++ using modern memory management techniques. Supports any comparable type, text and binary serialization, and all three standard traversal orders.

## Features

- Template class `BST<T>` — works with any type that defines comparison operators
- RAII memory management via `std::unique_ptr` (no manual `delete`)
- Full copy and move semantics (rule of five)
- Inorder, preorder, and postorder traversal
- Text-based and raw-binary serialization / deserialization
- Custom type support demonstrated with a `P_info` (person record) class
- Memory leak detection using `_CrtDumpMemoryLeaks` (MSVC debug builds)

## Build

Open `BST.sln` in Visual Studio 2019 or later and build. Targets: `Debug|x64`, `Release|x64`, `Debug|Win32`, `Release|Win32`.

## Code Highlights

### unique_ptr Node Ownership with Move Semantics

```cpp
// Source/BST.h — nested node class and BST move constructor

template<class T>
class node {
public:
    T val;
    std::unique_ptr<node> left;
    std::unique_ptr<node> right;

    node(T& _val) : val(_val), left(nullptr), right(nullptr) {}
    node() : val(NULL), left(nullptr), right(nullptr) {}
    node(node&& n) : val(n.val), left(n.left), right(n.right)
    {
        n.val = NULL;
        n.left = nullptr;
        n.right = nullptr;
    }
    // ...
};

// BST move constructor
template<class T>
inline BST<T>::BST(BST<T>&& tree) : root(move(tree.root))
{
    tree.root = NULL;
}

// BST move assignment
template<class T>
inline BST<T>& BST<T>::operator=(BST&& tree)
{
    root = move(tree.root);
    return *this;
}
```

The BST node stores its children as `std::unique_ptr`, so the entire subtree rooted at any node is automatically freed when that node is destroyed — no explicit traversal is needed for cleanup. The BST class itself implements both a move constructor and move assignment operator, transferring sole ownership of the root in O(1) by `std::move`-ing the `unique_ptr`. This makes temporary BST objects (e.g., function return values) cheap to handle without heap copying.

### Preorder Reinsertion for Structure-Preserving Copy

```cpp
// Source/BST.h

template<class T>
inline void BST<T>::_copy(std::unique_ptr<BST<T>::node<T>>& mainRoot,
                           std::unique_ptr<BST<T>::node<T>>& otherRoot)
{
    if (otherRoot == NULL)
    {
        return;
    }
    _insert(mainRoot, otherRoot->val);
    _copy(mainRoot, otherRoot->left);
    _copy(mainRoot, otherRoot->right);
}
```

Tree copying is implemented by a preorder traversal of the source tree followed by reinsertion into the destination. Because a BST's shape is determined entirely by the order in which values are inserted, visiting the source root before its children and reinserting in that same order guarantees that the destination tree has an identical structure — not merely the same set of values. This is a compact, correct approach that avoids any explicit node-cloning code.
