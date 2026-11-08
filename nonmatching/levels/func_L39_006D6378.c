/* Ported from rac4-decomp's func_L00_00766C00 (a twin of this function's code), names renamed from retail's
   relocations; 7 instruction(s) still differ under this file's flags. */
extern void *D_L39_0024D760;

void func_L39_006D6378(void *arg0) {
    void *temp_v1;
    temp_v1 = (*(void **)((u8 *)D_L39_0024D760 + 0x38));
    (*(s8 *)((u8 *)(temp_v1) + 0x14)) = 0;
    (*(s32 *)((u8 *)(temp_v1) + 0x18)) = (s32) (*(s32 *)((u8 *)(arg0) + 0x18));
}