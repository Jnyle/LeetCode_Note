# 题目描述:  合并两个有序链表

将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

**示例 :**
```
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
```
# 解题思路:
此题与剑指offer第25题一样，有两种方法

**方法一：** 直接法，非递归法，

新建一个虚拟节点，然后l3=dummyhead，然后一个一个节点的判断，如果l1->val<=l2->val，l3节点就指向l1，l1指向下一指针，否则指向l2，l2指向下一指针，直到有一个指针为空，然后l3下一指针指向另一非空的，返回dummyhead->next。

**方法二：** 递归法

先判断输入的链表是否为空的指针。如果第一个链表为空，则直接返回第二个链表；如果第二个链表为空，则直接返回第一个链表。如果两个链表都是空链表，合并的结果是得到一个空链表。

两个链表都是排序好的，我们只需要从头遍历链表，判断当前指针，哪个链表中的值小，即赋给合并链表指针即可。使用递归就可以轻松实现。
# 时间复杂度：
  方法一： O(n+m)
  
  方法二： O(n+m)
  
# 空间复杂度
  方法一：O(1)
  
  方法二：O(n+m)
  
# 代码

## [C++](./Merge-Two-Sorted-Lists.cpp):

###  方法一： 非递归法
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* dummyhead = new ListNode(-1);
        ListNode* l3 = dummyhead;
        if (l1==NULL) return l2;
        if (l2==NULL) return l1;
        if (l1==NULL && l2==NULL) return NULL;
        while(l1 && l2)
        {
            if (l1->val<=l2->val)
            {
                l3->next = l1;
                l1 = l1->next;
            }
            else
            {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }
        if (l1==NULL) l3->next = l2;
        if (l2==NULL) l3->next = l1;
        return dummyhead->next;
    }
};
```

###  方法二： 递归法
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Merge-Two-Sorted-Lists/Merge-Two-Sorted-Lists.py)
###  方法一：非递归法
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummyhead = ListNode(-1)
        l3 = dummyhead
        if l1==None:
            return l2
        if l2==None:
            return l1
        if l1==None and l2==None:
            return None
        while l1 and l2:
            if l1.val<=l2.val:
                l3.next = l1
                l1 = l1.next
            else:
                l3.next = l2
                l2 = l2.next
            l3 = l3.next
        if l1==None:
            l3.next = l2
        if l2==None:
            l3.next = l1
        return dummyhead.next
```
### 方法二 ：递归法
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1==None:
            return l2
        if l2==None:
            return l1
        if l1==None and l2==None:
            return None
        if l1.val<=l2.val:
            l1.next = self.mergeTwoLists(l1.next,l2)
            return l1
        else:
            l2.next = self.mergeTwoLists(l1,l2.next)
            return l2
```

# 参考

  -  [剑指offer_25题_合并两个排序的链表](https://github.com/bryceustc/CodingInterviews/blob/master/MergeSortedLists/README.md)
