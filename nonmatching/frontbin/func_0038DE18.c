/* func_0038DE18 (PAL frontbin, src/frontbin/38DBD8.c, flags -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
   -mno-check-zero-division), written from the assembly 2026-11-16. Near miss: 27 diff (tools/check.py).
   Every instruction is right in kind and the loop is retail's; what differs is register allocation
   (retail keeps `i` in $a2, the dead `data` register; this C gets $t0) and the prologue's order:
   retail computes the third table value as (data + count * 8) + 4 after the first two stores.
   Tried: data[0] with u32 pointers (27), `count = *data++` (44), byte arithmetic for the third
   value (43), a separate list pointer (44); 15 minutes of tools/permuter_engine.py reached its
   score 16 only with candidates that change what the code does. */
/* localdecomp:start func_0038DE18 */
typedef struct { u32 w0; u32 w4; } E_38DE18;
typedef struct { s32 count; E_38DE18 e[1]; } H_38DE18;
extern void *D_001D55D0[];
extern E_38DE18 *D_001D55D8[];
extern u8 *D_001D55E0[];
void func_0038DE18(s32 index, void *base, H_38DE18 *data) {
    s32 count = data->count;
    s32 i;
    D_001D55D0[index] = base;
    D_001D55D8[index] = data->e;
    D_001D55E0[index] = (u8 *)&data->e[count];
    for (i = 0; i < count; i++) {
        E_38DE18 *entry = &D_001D55D8[index][i];
        u32 word = entry->w0;
        u8 *p = D_001D55E0[index] + ((word >> 2) & 0x3FFC);
        if (p != 0 && p[3] != 0) {
            entry->w0 = word & 0xFFFF000F;
        }
    }
}
/* localdecomp:end func_0038DE18 */
