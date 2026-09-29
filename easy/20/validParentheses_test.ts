import assert from "node:assert/strict";
import { isValid } from "./validParentheses";

assert.equal(isValid("()"), true);
assert.equal(isValid("()[]{}"), true);
assert.equal(isValid("(]"), false);
assert.equal(isValid("([)]"), false);
assert.equal(isValid("{[]}"), true);

console.log("All tests passed!");