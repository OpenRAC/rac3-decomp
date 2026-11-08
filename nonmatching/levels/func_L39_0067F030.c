/* Ported from rac4-decomp's func_L01_00446AC0 (a twin of this function's code), names renamed from retail's
   relocations; 1 instruction(s) still differ under this file's flags. */
void func_003E82F8(void *);

void func_L39_0067F030(void *object) {
    *(s32 *)(object + 0xB8) = 0;
    func_003E82F8(object);
}