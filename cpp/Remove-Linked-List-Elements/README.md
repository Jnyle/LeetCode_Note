# 题目描述:  移除链表元素

删除链表中等于给定值 val 的所有节点。

**示例 :**
```
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
```

  
# 解题思路:
此题与剑指offer第18题删除链表中的节点

思路：使用哨兵节点，也就是虚拟头节点。

如果删除的节点是中间的节点，则问题似乎非常简单：
  - 选择要删除节点的前一个结点 prev。
  - 将 prev 的 next 设置为要删除结点的 next。
  
  ![1](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Remove-Linked-List-Elements/Images/1.png)
当要删除的一个或多个节点位于链表的头部时，事情会变得复杂。
  ![2](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Remove-Linked-List-Elements/Images/2.jpg)
可以通过哨兵节点去解决它，哨兵节点广泛应用于树和链表中，如伪头、伪尾、标记等，它们是纯功能的，通常不保存任何数据，其主要目的是使链表标准化，如使链表永不为空、永不无头、简化插入和删除。
  ![3](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Remove-Linked-List-Elements/Images/3.jpg)
在这里哨兵节点将被用于伪头。

**算法：**

  - 初始化哨兵节点为 ListNode(-1) 且设置 p.next = head。
  - 初始化两个指针 cur 和 prev 指向当前节点和前继节点。
  - 当 cur != NULL：
  - 比较当前节点和要删除的节点：
  - 若当前节点就是要删除的节点：则 prev.next = cur.next。
  - 否则设 prve = cur。
  - 遍历下一个元素：cur = curr.next。
  - 返回 p.next。
 
# 时间复杂度：
   O(n)。
# 空间复杂度
  O(1)
# 代码

## [C++](./Remove-Linked-List-Elements.cpp):

###  哨兵节点
```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = new ListNode(-1);
        p->next = head;
        ListNode* prev = p;
        ListNode* cur = head;
        ListNode* del = NULL;
        while(cur)
        {
            if (cur->val==val)
            {
                prev->next = cur->next;
                del = cur;
            }
            else
            {
                prev = cur;
            }
            cur = cur->next;
            if (del)
            {
                delete del;
                del = NULL;
            }
        }
        ListNode* res = p->next;
        delete p;
        return res;
    }
};
```
## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Remove-Linked-List-Elements/Remove-Linked-List-Elements.py)
###  哨兵节点
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        p = ListNode(-1)
        p.next = head
        prev = p
        cur = head
        while cur:
            if cur.val == val:
                prev.next = cur.next
            else:
                prev = cur
            cur = cur.next
        return p.next
```
# 参考
  - [剑指offer第18题-删除链表中的节点](https://github.com/bryceustc/CodingInterviews/blob/master/PrintListInReversedOrder/README.md)

