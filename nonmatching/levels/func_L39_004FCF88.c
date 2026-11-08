/* Ported from rac4-decomp's func_L00_00538D98 (a twin of this function's code), names renamed from retail's
   relocations; 6 instruction(s) still differ under this file's flags. */
s32 func_L39_004FC370(void *);

void func_L39_004FCF88(void *arg0) {
    (*(s32 *)((u8 *)(arg0) + 0)) = 0;
    (*(s32 *)((u8 *)(arg0) + 8)) = 0;
    func_L39_004FC370(arg0 + 0xC);
    func_L39_004FC370(arg0 + 0x20);
    func_L39_004FC370(arg0 + 0x34);
    (*(s32 *)((u8 *)(arg0) + 0x50)) = 0;
}