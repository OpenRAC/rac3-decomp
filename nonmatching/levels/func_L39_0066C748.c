/* Near miss, ported from rac4-decomp's func_L00_006F55E8 (cross-game near pair). NEAR: 9 diff: 72-byte struct fixes mult const (sra 3); remaining only reg alloc/sched (addr lui $v1, mult $ac3 vs $ac2) */
typedef struct {
    u8 pad0[0x18];
    s32 index;
    s32 f1C;
    s32 f20;
    u8 pad24[0x20];
    s32 f44;
} S_66C748;

extern S_66C748 D_L39_00343318[];

void func_L39_0066C748(S_66C748 *entry) {
    s32 index = entry - D_L39_00343318;
    entry->f44 = -1;
    entry->f1C = 0;
    entry->f20 = 0;
    entry->index = index;
}
