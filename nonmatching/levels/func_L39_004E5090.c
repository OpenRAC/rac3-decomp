/* Near miss, ported from rac4-decomp's func_L00_00520E90 (cross-game near pair). NEAR: body equal (struct copy + guard); library-style 16-byte sd save slots (frame 0x30) vs ours; type renamed S_4E5090 to avoid clash with Type1 in file context */
typedef struct S_4E5090 {
    int f0, f4, f8, fc, f10;
} S_4E5090;
extern S_4E5090 D_L39_0046D330;
extern int D_L39_0046D344[];
extern S_4E5090 *func_L39_004E9D70(int);

S_4E5090 *func_L39_004E5090(void) {
    if (D_L39_0046D344[0]) {
        D_L39_0046D330 = *func_L39_004E9D70(0);
        D_L39_0046D344[0] = 0;
    }
    return &D_L39_0046D330;
}