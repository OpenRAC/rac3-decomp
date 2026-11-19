/* functional: high. Near miss (16 diffs, store order and one register); same behaviour: 0x801 on bad tag/too short, 0 on success. */
typedef struct In_0050DC08 {
    char pad0[0xC];
    u8 *p;
    s32 n;
} In_0050DC08;

typedef struct Out_0050DC08 {
    u8 *p;
    s32 n;
    s32 tag;
} Out_0050DC08;

s32 func_L39_0050DC08(In_0050DC08 *in, Out_0050DC08 *out) {
    u8 *p = in->p;
    u32 tag = *p;

    if (tag < 8) {
        if (tag != 0) {
            if ((u32)in->n < 2) {
                return 0x801;
            }
        }
        if (in->n == 1) {
            out->tag = 0;
            out->p = 0;
            out->n = 0;
        } else {
            out->p = p + 1;
            out->n = in->n - 1;
            out->tag = *in->p;
        }
        return 0;
    }
    return 0x801;
}
