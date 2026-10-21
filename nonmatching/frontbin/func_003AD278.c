/* US draft of func_003AD278 (rac3-uya-decomp func_003A7CD0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003AD278 */
void func_003873C0();
void func_003ACC38(void *);
void func_003AD270(void *);
typedef struct { u8 pad0[0xB0]; f32 fB0; } S_00225980_003A7CD0_003A7CD0;
extern S_00225980_003A7CD0_003A7CD0 D_00225900[];

void func_003AD278(void *arg0) {
    f32 temp_f20;
    s32 temp_v1;

    if (*(*(f32 **)((u8 *)(arg0) + 4)) != 0.0f) {
        temp_f20 = D_00225900->fB0;
        D_00225900->fB0 = 0.62f;
        func_003873C0();
        temp_v1 = (*(s32 *)((u8 *)(arg0) + 0x1A8));
        switch (temp_v1) {                          /* irregular */
        case 0:
            func_003ACC38(arg0);
            break;
        case 2:
            func_003AD270(arg0);
            break;
        }
        D_00225900->fB0 = temp_f20;
        func_003873C0();
    }
}
/* localdecomp:end func_003AD278 */
