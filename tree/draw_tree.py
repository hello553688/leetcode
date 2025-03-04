import graphviz

class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def deserialize(data):
    if not data:
        return None
    root = TreeNode(data[0])
    queue = [root]
    i = 1
    while queue:
        node = queue.pop(0)
        if i < len(data) and data[i] is not None:
            node.left = TreeNode(data[i])
            queue.append(node.left)
        i += 1
        if i < len(data) and data[i] is not None:
            node.right = TreeNode(data[i])
            queue.append(node.right)
        i += 1
    return root

def draw_tree(root):
    dot = graphviz.Digraph()
    if not root:
        return dot
    queue = [(root, 0)]
    while queue:
        node, level = queue.pop(0)
        dot.node(str(id(node)), label=str(node.val))
        if node.left:
            dot.node(str(id(node.left)), label=str(node.left.val))
            dot.edge(str(id(node)), str(id(node.left)))
            queue.append((node.left, level + 1))
        if node.right:
            dot.node(str(id(node.right)), label=str(node.right.val))
            dot.edge(str(id(node)), str(id(node.right)))
            queue.append((node.right, level + 1))
    return dot

null=None
data = [1,null,2,null,3,null,4,null,5]
root = deserialize(data)
dot = draw_tree(root)
dot.render('binary_tree', format='png', cleanup=True)
