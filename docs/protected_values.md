# Protected values (levels 39-53)

The multiplayer code in levels 39-53 keeps many game-state values scrambled. The struct holds only a
one-byte handle `h`. The value itself is spread over a pool (`D_L39_004997E0` with stride 0xFF,
`D_L39_00480760` with stride 0xC1, `D_L39_00483A00` with stride 0xD1) and XOR-ed with a key read at
`D_L39_0024B9C8 * (u32)h % N`. The read helpers (Dec/Dec2/Dec3/DecF/Dec16/DecB) are proven by
func_L39_0065D0A0, which matches. This note covers the write helpers (Set/Set3/Set16/SetB).

## The second copy of the handle

Most retail Sets that store a non-zero value keep two registers holding the same handle pointer:

```
addiu $t2, $s2, 0x1A25      # h
lbu   $v0, 0x1A25($s2)
bnez  $v0, ...
 move $t0, $t2              # copy of h, made ahead of the *h == 0 test
...
mult  $a0, $t0, $a0         # the key multiply is the copy's only use
subu  $v0, $t2, $v0         # every other use reads $t2
```

Sets that store a constant 0 have no copy. Statement order, variable types and nested Key/Store inlines
don't produce it. With SN cc1 2.95.3, inline integration hands a user variable straight to the callee's
parameter, so a nested inline never gets its own copy. Neither does C++ (cc1plus, member functions, a
`const u32 &` value), because the tree is the same.

What does produce it is a second user variable that holds the same pointer:

```c
static inline void Set(u8 *q, u32 v) {
    u8 *hk = q;                 /* used only by the key */
    ...
    Prep(q);
    key = ((u32 *)pool)[((u32)hk * D_L39_0024B9C8) % N];
    k = ((u32)q - *q) & 7;      /* first read of *q, before the buffer stores */
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = enc(v) ^ key;
    m = *q + 1;                 /* second read, after them */
    ...
}
```

This is how the compiler handles it, as the RTL dumps (`-da`) show:

- CSE1 records `hk = q`. The key multiply sits after the Prep if/else, in a block CSE1 enters fresh, so
  CSE1 leaves the multiply on `hk`.
- GCSE's cprop pass makes no copy propagations in these functions ("0 copy props" in the .gcse dump),
  so the copy is still there when registers are allocated.
- Both pointers are live across the if/else, so they get different hard registers. That gives retail's
  `move` in the branch delay slot.
- `(u32)hk * D` and not `D * (u32)q`: retail's multiply has the handle first (`mult rd, h, D`) at every
  Set site, with or without the copy.

Reading `*q` twice, once before the buffer stores and once after, gives retail's second copy (`n`):
`lbu $v0; move $v1, $v0`, with `subu` on `$v0` and `m = n + 1` on `$v1`. One load is kept and the
second value becomes a register copy, which fits a GCSE load redundancy across the stack stores to
`buf`. This step is inferred from the output; the dumps weren't traced for it. Reading `*q` once into
`n` loses the copy.

Zero stores need a helper without `hk` (`Clr...`): the same code with the value folded to 0.

A third-argument form, `Set(&x, v, &x)`, reproduces the copy only where the index is a constant (CSE1
folds both address computations to `s + c`). With a variable player index `&s->h1F[b]`, SN expands each
argument in place (`p = b + s; p = p + c`), CSE1 can't prove the two values equal, and the copy is lost.

## Effect (stock checker, aligned opcode / full-instruction similarity)

| Function | before | after |
|---|---|---|
| func_L39_00640738 (12.7 KB) | 96.5% / 87.2%, 3140 rows differ | 97.4% / 88.8%, 1242 rows differ |
| func_L39_0064EA40 (32.9 KB) | 94.9% / 77.4% | 98.3% / 84.1% |
| func_L39_00656F28 (24.4 KB) | 89.4% / 35.2% | 90.4% / 38.7% |

In all three, the copy-or-not pattern of the Set sites now follows retail. 0064EA40 has 31 copied
0x19E6 stores and 4 zero stores without a copy. Two things don't follow it yet. In 0064EA40, the first
Set (`Set(g + 0x19E4, cmd)`) gets an extra `hk` copy where retail's multiply reads `h` itself. In
00656F28, the stack-temporary layout described in its header still dominates.

## More sites (2026-11-08, second pass)

Matching the small L39 functions (func_L39_0063AC60, func_L39_00629098, func_L39_00628428,
func_L39_00673B68) and re-reading the giants refined the rule:

- **The copy follows the site, not the value.** A zero store can keep the copy too: func_L39_00629098's
  `Set16(g + 0x313, 0)` and 0064EA40's `SetB(g + 0x1A18, 0)` have `move $a2, $s0` and store the zero
  through a register (`move $v0, $zero; sh/sb $v0`). Those go through the hk Set with a literal 0; only
  sites with no copy and `sb/sh $zero` use the Clr helpers.
- **A site with a long-lived copy of its own needs no hk.** 0064EA40's first `Set(g + 0x19E4, cmd)`
  multiplies by the handle itself because g + 0x19E4 is also kept in `$s5` for the rest of the function
  (copied in the Set's delay slot). A Set without hk there reproduces it.
- **Other pools.** Besides D_L39_004997E0 (stride 0xFF, key % 510) and D_L39_00480760 (0xC1, % 386), there
  are D_L39_00483A00 (0xD1, % 418) and D_L39_0049C340 (0x81, % 258). Their Set16/SetB write the key, then
  k, then the value, then `buf.w[0]` before `buf.w[1]` (func_L39_00673B68); D_L39_0049C340 indexes
  `D[m + ((k + i) & 7) * 129]`, D_L39_00483A00 `D[((k + i) & 7) * 209 + m]`.
- **A float Set** (func_L39_00628428, g + 0x2476): `buf.w[0] = q ^ key; buf.f[1] = v; buf.w[1] ^= key;`.
- **The handle pointer as a variable.** func_L39_00673B68 needs `u8 *q = p + 1;` shared by the Dec and the
  Set of a read-modify-write, and the bit `(s16)(1 << b)` computed first.


## The player struct is 16-byte aligned (2026-11-08)

Making the player struct `Pl_00640738` `aligned(16)` restores retail's `(s + b*0x50) + off` address
form. With 4-byte alignment, expand_expr folds the field offset into the base and GCSE hoists
`s + off` out as a shared value, so the stores come out in a different shape. When a function
indexes an array of such structs and retail adds the field offset last, give the struct type the
16-byte alignment rather than reordering the C. See the header of
nonmatching/levels/func_L39_00640738.c and commit e1730a8.
