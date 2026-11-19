/* functional: high. Retail bytes differ by one alignment nop only (30 diff); behaviour identical to asm: spatial trigger update (sphere/path/volume test of hero position vs settings, then notifies lists and mobys on change). */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    s32 path;
    f32 radius;
    s32 volumes[6];
    s32 lists[12];
    s32 mobys[11];
    s8 switches[4];
} SpatialTriggerSettings_L19;

extern u128_t D_L19_001E2080;
extern u128_t D_001A4C60;
extern u8 *D_L19_0021D500[];
extern f32 func_0038CF00(void *, void *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_004463F8(void *, void *, s32);
extern void func_L04_003C8DA0(u8 *, void *, s32, s32);
extern void func_L19_00302700(s32, void *, s32);

void func_L19_00302998(u8 *object)
{
    SpatialTriggerSettings_L19 *settings;
    u128_t point;
    s32 flag = 0;
    s32 i;
    s32 j;
    s32 k;
    s32 *mobys;
    s32 forced;
    u8 *path;

    settings = *(SpatialTriggerSettings_L19 **)(object + 0x68);
    object[0x30] = 0xFF;
    if (settings->switches[2])
        point = D_L19_001E2080;
    else
        point = D_001A4C60;
    forced = object[0x95];
    if (forced == 0) {
        if (settings->radius > 0.0f && func_0038CF00(object + 0x10, &point) < settings->radius)
            flag = 1;
        if (!flag) {
            if (settings->path != -1) {
                path = D_L19_0021D500[settings->path];
                flag = func_L01_004463F8(&point, path + 0x10, *(s32 *)path) != 0;
            }
        }
        if (!flag) {
            for (i = 0; ; i++) {
                if (i >= 6)
                    goto done;
                if (settings->volumes[i] == -1)
                    continue;
                if (func_00382380(&point, settings->volumes[i], 0))
                    break;
            }
            goto set;
        }
    } else {
        do {
            if (forced == 1) {
set:
                flag = 1;
            } else {
                flag = 0;
            }
        } while (0);
    }
done:
    if ((flag && !object[0xBC]) || (!flag && object[0xBC]) || !object[0x20]) {
        if (flag)
            object[0xBC] = 1;
        else
            object[0xBC] = 0;
        object[0x20] = object[0xBC] + 1;
        mobys = settings->mobys;
        for (j = 0; j < 12; j++) {
            if (settings->lists[j] != -1)
                func_L04_003C8DA0(object, settings, settings->lists[j], flag);
        }
        for (k = 0; k < 11; k++) {
            if (mobys[k] != -1)
                func_L19_00302700(mobys[k], settings, flag);
        }
    }
}
