/* Near miss of func_003CE5E8 with its file's own flags: tools/check.py reports 40 diff
   (the US draft it started from: 75).
   What differs: Structure/addressing now match retail (75 -> 40 word diffs); what is left is
   gcc register allocation and scheduling only: (1) callee-saved permutation in the loop -
   retail $s1=base+h1C, $s2=items walk, $s3=the q->items[i] induction pointer, $s4=the
   0x70003F00 flag pointer, mine has $s1=items, $s2=base+h1C, $s3=flag pointer, $s4=induction
   pointer; (2) setup block temps - retail loads the pointer global into $a0/$a1/$v0/$v1 for
   the four stores and splits D_1422E0's lui/addiu across the first store, mine uses
   $v1/$v0/$v1/$a0 and keeps lui+addiu adjacent; (3) tail - the D_1A1ED0 base/constant...
*/

/* Candidate for func_003CE5E8 (PAL). Based on the US draft, with PAL retail's
   addressing: the pointer global is read through an unsized array (lui/lw) and
   written through a sized pointer ($gp). */

typedef E_3C8ED0 E_3C9078;
typedef struct { s16 n; u16 flags; u8 pad[0xC]; E_3C9078 items[1]; } S_3C9078;
extern u32 *D_001DA050_003CE5E8;
extern u32 *D_001DA050_003CE5E8_r[];
extern u8 D_1422E0[];
extern s32 D_1A1ED0[];
extern void func_003CED08(E_3C9078 *, s32, u8 *);
extern void func_003CE780(void);
extern s32 func_003CE828(u8 *, u8 *, s32);
extern void func_003CE920(s32, u8 *, u8 *, u8 *);
extern void func_003A9440(s32, unsigned long);
void func_003CE5E8(Q_3C8E70 *arg) {
    S_3C9078 *q = (S_3C9078 *)arg;
    E_3C9078 *e;
    u8 *fl;
    s32 i;
    if (q->n != 0) {
        func_003CED08(q->items, q->n, (u8 *)0x70003F00);
        func_003CE780();
        fl = (u8 *)0x70003F00;
        e = q->items;
        D_001DA050_003CE5E8_r[0][0] = 0x30000007;
        D_001DA050_003CE5E8_r[0][1] = (u32)D_1422E0;
        D_001DA050_003CE5E8_r[0][2] = 0;
        D_001DA050_003CE5E8_r[0][3] = 0x50000007;
        D_001DA050_003CE5E8 = D_001DA050_003CE5E8_r[0] + 4;
        for (i = 0; i < q->n; i++, e++, fl++) {
            if (*fl == 0) {
                u8 *b = e->base;
                u8 *c = b + e->h1C;
                u8 *a0 = b + e->h18;
                u8 *d = b + e->h1A;
                if (func_003CE828(a0, (u8 *)0x70000000, e->h14) == 0) {
                    func_003CE920(q->items[i].h16, c, d, (u8 *)0x70000000);
                }
            }
        }
        func_003A9440(0x47, 0x3180B);
        {
            s32 *d1 = D_1A1ED0;
            func_003A9440(0x4E, ((d1[2] >> 13) | 0x1000000) | 0x100000000L);
        }
    }
}
