import assert from "node:assert/strict";
import { ListNode, removeNthFromEnd } from "./removeNthFromEnd";

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

assert.equal(removeNthFromEnd(null, 1), null);
assert.deepEqual(listValues(removeNthFromEnd(makeList([1]), 1)), []);
assert.deepEqual(listValues(removeNthFromEnd(makeList([1, 2]), 1)), [1]);
assert.deepEqual(listValues(removeNthFromEnd(makeList([1, 2]), 2)), [2]);
assert.deepEqual(listValues(removeNthFromEnd(makeList([1, 2, 3]), 2)), [1, 3]);
assert.deepEqual(listValues(removeNthFromEnd(makeList([1, 2, 3, 4, 5]), 2)), [1, 2, 3, 5]);