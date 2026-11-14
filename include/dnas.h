#ifndef DNAS_H
#define DNAS_H

/* The protection stubs of Sony's DNAS client library (level 39, the multiplayer menu). Only these
 * may be asm in the library's matched C, and only around the blocks retail stores encrypted
 * (AGENTS.md, "Matching rules"; docs/build/dnas.md).
 *
 * 112 runs of the library's code are stored encrypted in `.text`. Each sits inside a function,
 * between a stub that decrypts it and, for 94 of them, one that encrypts it again:
 *
 *     DNAS_BEGIN(func_L39_004B4620, 0, func_L39_004BD350);
 *     D_L39_00464634 = *a0;
 *     DNAS_END(func_L39_004B4620, 0, func_L39_004BD350);
 *
 * The arguments name the block: the function it is in, its number there (in address order, from
 * 0) and the library's driver (func_L39_004BD350 in the first library, func_L39_004F7890 in the
 * second; `driver(block, k1, k2, k3)`). The fifteen random words each block has on a disc (two
 * of the record's words and twelve filler words) are not written here: they differ between PAL
 * and NTSC-U for the same code. The macros leave them zero, and the build fills them in from the
 * version's table and encrypts the block (tools/dnas.py, on the object, before linking).
 *
 * The evidence (2026-11-14; both discs' level 39, every one of the 112 blocks decrypted with the
 * level's own routines and encrypted back to the stored bytes):
 * - every block decrypts to ordinary ee-gcc 2.96 `-O2 -G0` code (4,896 words reached, all valid;
 *   no branch leaves its function), and the function around it is one frame: the prologue before
 *   the stub and the epilogue after it belong to the plaintext. The functions were C;
 * - the stub is a statement, not a cut through compiled code: it always follows a whole prologue
 *   or sits between statements, values needed after it are in saved registers before it, the
 *   return value is set after the second call. That is what the compiler does around a call;
 * - the flag test, the argument loads and the `jal` are the compiler's: in 6 of the 94 second
 *   calls its own instructions are scheduled between the loads, in one the loads are in the
 *   other order, and in one first stub its reload of a register sits between the `jal` and the
 *   `b`. So they are C here;
 * - the two address loads are not: in all 112 first stubs and all 94 second ones each is an
 *   adjacent `lui`/`addiu` on one register (an assembler `la`), where the compiler's own address
 *   loads in the same functions are split and scheduled apart. And no compiler emits a `b` over
 *   words that are not code. So the `la`s, the `b`, the filler and the record are asm here, and
 *   nothing else;
 * - four functions written with these macros build to retail's stored bytes on both discs, in
 *   level 39 builds that say MATCH (func_L39_004B4620, func_L39_004B4BA0, func_L39_004CDB18,
 *   func_L39_004CCBD8 and their NTSC-U twins), with SN's assembler and with Sony's. The forms
 *   that do not: the stub all in C (the `lui` is lifted into the prologue), all in asm with a
 *   clobber list (the block then uses saved registers where retail uses $v0/$v1), a plain
 *   marker call (its delay slot is filled from the prologue), and these macros with
 *   non-volatile `la`s (they are scheduled away).
 *
 * The wording of the macros is ours; what the evidence fixes is the split between C and asm.
 * No register is pinned and nothing is scheduled by hand. Use them only where retail has the
 * stub, with the function's own name and the block's number (tools/dnas_blocks.py --show
 * prints a function with its blocks decrypted and numbered). */

/* The stub in front of block `n` of function `fn`: when the record's flag is clear, decrypt the
 * block; then the `b` over the six filler words and the record {flag, k2, k3, k1, 0}. The build
 * step writes the filler, k2 and k3; k1 is k2 ^ the block's length, which the record holds
 * here. */
#define DNAS_BEGIN(fn, n, crypt) \
    { \
        unsigned int *dnas_r; \
        __asm__ volatile ("la\t%0,dnas_rec_" #fn "_" #n : "=r" (dnas_r)); \
        if (dnas_r[0] == 0) { \
            int dnas_b; \
            __asm__ volatile ("la\t%0,dnas_blk_" #fn "_" #n : "=r" (dnas_b)); \
            crypt(dnas_b, dnas_r[3], dnas_r[1], dnas_r[2]); \
        } \
        __asm__ volatile ( \
            "b\tdnas_blk_" #fn "_" #n "\n" \
            "\t.word\t0,0,0,0,0,0\n" \
            "dnas_rec_" #fn "_" #n ":\n" \
            "\t.word\t0,0,0,dnas_end_" #fn "_" #n "-dnas_blk_" #fn "_" #n ",0\n" \
            "dnas_blk_" #fn "_" #n ":"); \
    }

/* What follows a block: the `b` over six filler words and the second record {k2e, k3e, k1e, 0}.
 * 18 blocks (the library's allocator) have only this: they are decrypted once and stay so. */
#define DNAS_END_ONCE(fn, n) \
    __asm__ volatile ( \
        "dnas_end_" #fn "_" #n ":\n" \
        "\tb\tdnas_aft_" #fn "_" #n "\n" \
        "\t.word\t0,0,0,0,0,0\n" \
        "dnas_rec2_" #fn "_" #n ":\n" \
        "\t.word\t0,1,dnas_end_" #fn "_" #n "-dnas_blk_" #fn "_" #n ",0\n" \
        "dnas_aft_" #fn "_" #n ":")

/* The end of block `n` of function `fn`, and the call that encrypts it again. */
#define DNAS_END(fn, n, crypt) \
    { \
        unsigned int *dnas_r; \
        int dnas_e; \
        DNAS_END_ONCE(fn, n); \
        __asm__ volatile ("la\t%0,dnas_rec2_" #fn "_" #n : "=r" (dnas_r)); \
        __asm__ volatile ("la\t%0,dnas_end_" #fn "_" #n : "=r" (dnas_e)); \
        crypt(dnas_e, dnas_r[2], dnas_r[0], dnas_r[1]); \
    }

/* Text inside a block. Retail stores the text a protected block's code reads inside the block, so
 * that it is encrypted with the code: a `b` over it with a `nop` in its delay slot, two zero
 * words, the text and its NUL, zero bytes up to the next 8-byte boundary, a `nop` (the `b`'s
 * target), then an adjacent `lui`/`addiu` of the text's address into the register the code uses.
 *
 * The evidence (2026-11-14; both discs' level 39, all 112 blocks decrypted; two independent
 * reviews, and the survey counted again for the maintainer's ruling):
 * - all 65 text sites, in the 30 blocks that hold text (15 functions, both libraries), have
 *   exactly this sequence, on PAL and on NTSC-U (the same sites; the texts differ only in
 *   `eu`/`us` in the server names); level 39 has it nowhere outside a block. The two DER
 *   certificate blocks (func_L39_004B8208, func_L39_004BAA78) put 12 binary tables in the same
 *   envelope; they are not text and not covered (one of them has no NUL at all);
 * - the address load is asm, not the compiler's: ee-gcc 2.96 writes its own as `%hi`/`%lo` and
 *   splits and schedules them (lifting the `lui` into the prologue, filling a following `jal`'s
 *   delay slot with the `addiu`), while retail's text loads are never split, and 21 of the 22
 *   followed by a `jal` leave its slot a `nop` (the 22nd holds an unrelated `move`);
 * - 2.96 keeps one copy of a literal per file, where retail stores the text again at each use
 *   (`modified (page-) pointer.` four times in two functions, `debug_fermat/ng/busy` twice in
 *   func_L39_004D6488's one block); and no C form puts data inline in a
 *   function behind a branch: on func_L39_004B7A80 (free) a string literal, a file-scope array,
 *   a named extern at the text's address and a `section(".text")` array give 67 diff on PAL and
 *   68 on NTSC-U (the text leaves the block, which shrinks), the `b` and the text in asm with
 *   the address taken in C 43, this macro without `volatile` 33, without `.set noreorder` 39
 *   (Sony's ee-as, the library's) or 63 (SN's assembler). The code around each site is the
 *   compiler's code around an opaque `asm volatile` (the `switch` of func_L39_004D6488);
 * - `volatile` because the asm puts a branch and data into the instruction stream: without it
 *   the compiler may move, merge or drop it. `.set noreorder` because Sony's assembler otherwise
 *   moves the instruction before the `b` into its delay slot and the `addiu` into the delay slot
 *   of a `jal` after it; retail has neither. It acts only on the asm's own instructions (as in
 *   abs_asm), inside `.set push`/`.set pop`;
 * - the functions written with it check MATCH on both discs, with SN's assembler and with
 *   Sony's, and build to MATCH in level 39 (func_L39_004B7748 and func_L39_004B7A80, the
 *   allocator's malloc and free).
 * The value is the text's address; the compiler picks the register. `.align 3` is relative to
 * the file's `.text`, whose functions start 8-aligned as retail's do.
 *
 * Use it only between a block's DNAS_BEGIN and its DNAS_END/DNAS_END_ONCE, only where the
 * decrypted block (tools/dnas_blocks.py --show) has this sequence, with exactly one string
 * literal that is the text retail stores there: no concatenated literals (the assembler would
 * store each part with its own NUL), no macro name (it is stringized, not expanded), no `%` (a
 * format character in an asm with operands; no retail text has one). Text only: never for
 * binary data; the two DER certificate blocks stay out. */
#define DNAS_STRING(text) \
    ({ \
        char *dnas_s; \
        __asm__ volatile ( \
            ".set\tpush\n" \
            "\t.set\tnoreorder\n" \
            "\tb\t9f\n" \
            "\tnop\n" \
            "\t.word\t0,0\n" \
            "8:\t.asciz\t" #text "\n" \
            "\t.align\t3\n" \
            "9:\tnop\n" \
            "\tla\t%0,8b\n" \
            "\t.set\tpop" : "=r" (dnas_s)); \
        dnas_s; \
    })

#endif
