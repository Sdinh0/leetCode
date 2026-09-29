import assert from "node:assert/strict";
import { ListNode, mergeTwoLists } from "./mergeTwoLists";

function makeList(values: number[]): ListNode | null {
    return values.reduceRight<ListNode | null>(
        (next, value) => new ListNode(value, next),
        null,
    );
}

function listValues(head: ListNode | null): number[] {
    const values: number[] = [];
    while (head) {
        values.push(head.val);
        head = head.next;
    }
    return values;
}

assert.equal(mergeTwoLists(null, null), null);
assert.deepEqual(listValues(mergeTwoLists(makeList([1, 2, 4]), makeList([1, 3, 4]))), [1, 1, 2, 3, 4, 4]);
assert.deepEqual(listValues(mergeTwoLists(makeList([]), makeList([]))), []);
assert.deepEqual(listValues(mergeTwoLists(makeList([]), makeList([0]))), [0]);
assert.deepEqual(listValues(mergeTwoLists(makeList([2]), makeList([1]))), [1, 2]);