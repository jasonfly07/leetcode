# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a list node
    # @return a tree node
    def sortedListToBST(self, head):
        if head == None:
            return None

        nodeList = []
        currListNode = head
        while True:
            nodeList.append(currListNode)
            currListNode = currListNode.next
            if currListNode == None:
                break

        return self.sortedListToBST_help(nodeList, 0, len(nodeList)-1)

    def sortedListToBST_help(self, nodeList, start, end):
        if start == end:
            return TreeNode(nodeList[start].val)
        elif start > end:
            return None
        else:
            mid = (start+end)/2
            subRoot = TreeNode(nodeList[mid].val)
            leftSubTree  = self.sortedListToBST_help(nodeList, start, mid-1)
            rightSubTree = self.sortedListToBST_help(nodeList, mid+1, end)

            subRoot.left  = leftSubTree
            subRoot.right = rightSubTree

            return subRoot




def main():
    ln1 = ListNode(1)
    ln2 = ListNode(2)
    # ln3 = ListNode(3)
    # ln4 = ListNode(4)

    ln1.next = ln2
    # ln2.next = ln3
    # ln3.next = ln4

    s1 = Solution()
    print s1.sortedListToBST(ln1).val



if __name__ == "__main__":
    main()