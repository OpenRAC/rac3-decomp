/* Near miss, ported from rac4-decomp's func_L00_00519050 (cross-game near pair). NEAR: SIBCALL (tail j func_L00_004BEF28) + SQ_RA; global is lui 0x47 +0x6270 (D_00476270 by address) */
typedef struct S_004DD250 S_004DD250;
struct S_004DD250 {
    char _p0[0x4];
    s32 f4;
    char _p8[0x4];
    s32 fC;
};
extern char D_00476270[];
s32 func_L00_004BECF0(s32, s32, s32, s32, s32);
s32 func_L00_004BEF28(void *);
s32 func_L00_004E2D68(s32);
s32 func_L00_004E47F8(s32);

void func_L39_004DD250(S_004DD250 *arg0) {
    s32 temp_a0;
    s32 temp_a0_2;
    if (arg0 != 0) {
        if (func_L00_004BECF0((char *)arg0 + 0x10, -1, 0x17, D_00476270, 0x70) <= 0) {
            temp_a0 = arg0->fC;
            if (temp_a0 != 0) {
                func_L00_004E2D68(temp_a0);
            }
            temp_a0_2 = arg0->f4;
            if (temp_a0_2 != 0) {
                func_L00_004E47F8(temp_a0_2);
            }
            func_L00_004BEF28(arg0);
        }
    }
}
