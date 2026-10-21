#!/bin/sh
# tools/carry_us.sh: carry src/ to the NTSC-U disc (docs/versions.md). Run it after any change to
# src/ and before every push, on a Linux machine with the toolchains and the dumps of both discs
# (tools/levels.py dump, tools/levels.py --version us dump):
#
#     TOOLCHAINS=~/Projects/RAC/rac3-toolchains JOBS=32 sh tools/carry_us.sh
#
# 1. tools/version_map.py --write: PAL's source checked on NTSC-U (only changed files again);
# 2. tools/c_objects.py: each function that checks MATCH compiled alone, as the check compiles it;
# 3. tools/asm_build.py --version us --c: the 54 NTSC-U programs built with that C linked in, each
#    checked byte for byte against the disc;
# 4. tools/c_objects.py --collect: config/us/built.tsv, what each program builds from C;
# 5. both progress reports. Then commit config/us/, progress/ and README.md with the change.
#
# To split step 3 across machines, run steps 1-3 for a share of the targets on each (the targets
# as arguments to c_objects.py and asm_build.py), copy each machine's build/us/*/c_functions.txt
# and build/us/cobj/index.tsv back, and pass the copies' folders to --collect.
set -e
cd "$(dirname "$0")/.."
T=${TOOLCHAINS:-$HOME/Projects/RAC/rac3-toolchains}
PY=${PYTHON:-python3}
J=${JOBS:-16}
TC="--toolchain $T/eegcc_2.95.3_sn_v1.36 --runner $T/wibo --ee29 $T/sn-prodg-24-ee/gcc"
$PY tools/version_map.py --write -j "$J" $TC
$PY tools/c_objects.py -j "$J" $TC
$PY tools/asm_build.py --version us --c -P "$J"
$PY tools/c_objects.py --collect
$PY tools/progress.py --write
$PY tools/progress.py --version us --write
$PY tools/version_map.py --check
