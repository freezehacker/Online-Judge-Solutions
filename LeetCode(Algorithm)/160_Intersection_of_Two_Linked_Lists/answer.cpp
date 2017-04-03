
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    	// 先排除这种情况，其中有一个是空链表，那么交集肯定也是不存在。
    	if ( !headA || !headB ) return NULL;

        ListNode *p1 = headA;	// p1从A出发
        ListNode *p2 = headB;	// p2从B出发

        while ( p1 != p2 ) {	// 只要p1与p2还没相遇
        	p1 = p1 ? p1->next : headB;	// p1继续走，如果走完了A就走B
        	p2 = p2 ? p2->next : headA;	// p2思路同p1
        }

        // 这时候，要么同时到达公共部分，要么同时到达NULL
        // 都可以返回结果了
        return p1;
    }
};
