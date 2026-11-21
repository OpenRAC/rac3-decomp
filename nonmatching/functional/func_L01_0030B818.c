/* functional: high. Written from the assembly: walks the 16 records of 0xB0 bytes at D_L01_00270FF0 and calls func_L01_0030B880 for those whose owner (+0xA0) is the object. 6 words differ (loop branch form). */
extern void func_L01_0030B880(s32, u8 *);

void func_L01_0030B818(void *arg0)
{
    s32 owner = (s32)arg0;
    u8 *record;
    u8 *end;

    record = (u8 *)D_L01_00270FF0;
    end = record + 0xB00;
    do {
        if (*(s32 *)(record + 0xA0) == owner) {
            func_L01_0030B880(owner, record);
        }
        record += 0xB0;
    } while (record < end);
}
