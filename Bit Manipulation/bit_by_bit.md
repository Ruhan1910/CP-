**Each bit act independently**

That little fact - that each bit acts independently in bitwise operations is super powerful, especially in competitive programming. It means you can opten solve problems
bit by bit, rther than treating numbers as a whole, you can just think about what happens at bit 0, bit 1, ....., bit 31. That's a tiny puzzle instead of one big one.

**Why is bitwise logic independent**

Because operations like AND, OR, XOR act on the corresponding bits. The bit at position i in the result depends only on the bits at position i in the inputs - never on
other porition. But that's not true for addition, which can carry over bit. it is true fro bitwise operation. That's why we love them for fast logic. 
