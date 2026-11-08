/* Level 02 (Florana), PAL. 4 diff with check.py --target level_02. register allocation only: retail loads `lw $v0,0xb8($a0)` and keeps the `lui`/`addiu` of the quadword source in `$a2`; this C uses `$v1` for `o->p` and `lui $v0; addiu $a2,$v0`. About 12 variants (do-while, while, a source-pointer local, statement order, with and without the `.extern` hint) did not move it. */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_3523D0;
typedef struct S_3523D0 {
    char pad0[0x2E4];
    int f2E4;
    int f2E8;
    int f2EC;
    V4_3523D0 v[1];
} S_3523D0;
typedef struct P_3523D0 { char pad[0x68]; S_3523D0 *s; } P_3523D0;
typedef struct O_3523D0 { char pad[0xB8]; P_3523D0 *p; } O_3523D0;
extern V4_3523D0 D_L02_001D66B0;
__asm__(".extern D_L02_001D66B0, 16");

void func_L02_003523D0(O_3523D0 *o) {
    S_3523D0 *s = o->p->s;
    int i;
    for (i = 15; i >= 0; i--) {
        *(V4_3523D0 *)((char *)(s->f2E8 * 16 + (int)s) + 0x2F0) = D_L02_001D66B0;
        s->f2E8 = 0;
        s->f2EC = 0;
        s->f2E4 = 0;
    }
}
