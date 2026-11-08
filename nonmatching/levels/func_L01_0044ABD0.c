/* func_L01_0044ABD0: near miss (p2w3 w2), only difference is one nop before each div.s (divs_nops), 120 diff rows by shifting
   retail: nop precedes both div.s f2,f0,f1 (2 places); everything else equal
   inlined (x*5+2)/6 timer conversion (no calls to the rac2 CE0/CF0 helpers); 49 places not checked */
extern s32 func_0038CB00(u8 *);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
void func_L01_0044ABD0(void *owner, u8 *obj) {
    s32 r, g, b;
    f32 limit, f;
    if (*(s16 *)obj == 0) return;
    if (func_0038CB00(obj) != 0) {
        if (*(s16 *)(obj + 2) != 0) {
            func_L01_0043B9E8(owner, obj[4], obj[5], obj[6]);
            return;
        }
        *(s16 *)(obj + 2) = 1;
        *(s16 *)obj = (*(s16 *)(obj + 0xE) * 5 + 2) / 6;
    }
    if (*(s16 *)(obj + 2) == 0) {
        limit = (f32)((*(s16 *)(obj + 0xC) * 5 + 2) / 6);
        f = (limit - (f32)*(s16 *)obj) / limit;
        r = obj[7] ? (s32)((f32)obj[4] + (f32)(obj[7] - obj[4]) * f) : obj[4];
        g = obj[8] ? (s32)((f32)obj[5] + (f32)(obj[8] - obj[5]) * f) : obj[5];
        b = obj[9] ? (s32)((f32)obj[6] + (f32)(obj[9] - obj[6]) * f) : obj[6];
    } else {
        limit = (f32)((*(s16 *)(obj + 0xE) * 5 + 2) / 6);
        f = (limit - (f32)*(s16 *)obj) / limit;
        r = obj[7] ? (s32)((f32)obj[7] + (f32)(obj[4] - obj[7]) * f) : obj[4];
        g = obj[8] ? (s32)((f32)obj[8] + (f32)(obj[5] - obj[8]) * f) : obj[5];
        b = obj[9] ? (s32)((f32)obj[9] + (f32)(obj[6] - obj[9]) * f) : obj[6];
    }
    func_L01_0043B9E8(owner, r, g, b);
}
