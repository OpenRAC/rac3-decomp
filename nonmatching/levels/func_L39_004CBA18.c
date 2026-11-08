/* Near miss, ported from rac4-decomp's func_L00_00507818 (cross-game near pair). NEAR: SQ_RA/16-byte save slots (retail frame 0x40: s0@0,s1@0x10,s2@0x20,ra@0x30; ours 0x20 with 8-byte slots) + a3/a0/a1 arg-set order around the first jal; calls right: func_L39_004BECC0, func_L39_004CBAA8, D_L39_00475EE8 */
typedef struct {
    char pad0[0x44];
    s32 f44;
} S_4CBA18;

extern char D_L39_00475EE8[];
extern void func_L39_004BECC0(s32, s32, char *, s32);
extern s32 func_L39_004CBAA8(s32, S_4CBA18 *);

s32 func_L39_004CBA18(s32 arg0, S_4CBA18 *arg1) {
    s32 result;
    char *base;
    if (arg1 != 0 && arg1->f44 != 0) {
        base = D_L39_00475EE8;
        func_L39_004BECC0(9, 0xC, base, 0x14B);
        result = func_L39_004CBAA8(arg0, arg1);
        func_L39_004BECC0(0xA, 0xC, base, 0x14D);
    } else {
        result = 0;
    }
    return result;
}
