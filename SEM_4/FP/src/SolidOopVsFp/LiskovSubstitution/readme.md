## Liskov Substitution Principle

```text
Let q(x) be a property provable about objects x of type T. Then q(y) should be true for objects y of type S where S is a subtype of T.
```

### Implementation notes:

Hmm, in general writing generic classes in Scala requires thinking about variances, at the same time, all collections in
c# are covariant and delegates can be contravariant. So I would prefer C# in this case.