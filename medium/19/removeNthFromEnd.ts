/* Definition for singly-linked list. */
export class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.next = (next===undefined ? null : next)
    }
}

function getLength(head: ListNode | null): number {
    let length = 0;
    while (head) {
        length++;
        head = head.next;
    }
    return length;
}

export function removeNthFromEnd(head: ListNode | null, n: number): ListNode | null {
    if (!head) return null;

    const length = getLength(head);
    const dummy = new ListNode(0, head);
    let current: ListNode | null = dummy;
    
    for (let i = 0; i < length - n; i++) {
        current = current!.next!;
    }
    
    current.next = current.next?.next || null;
    return dummy.next;
}