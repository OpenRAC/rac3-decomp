"""memo.py: tables kept between the checks of one tools/check_batch.py worker.

A loader marked @memo.kept reads its table as before, except in a worker of tools/check_batch.py
(memo.enable()), where its first result for given arguments is kept and given out again for the
same arguments, for the worker's lifetime. A worker lives inside one run of tools/c_objects.py, in
which the tree it reads does not change. The key of a kept result is the loader, its arguments,
the version (version.V, fixed for a process) and, for a loader marked target=True, UYA_TARGET (the
target targets.get() falls back to).

A kept result is shared, not copied: a loader is marked only when no caller changes what it
returns (each is listed with its callers in scratch/orch/batch/REPORT.md). memo.enable(verify=True)
checks that after every check: it keeps a pickle of each result and memo.verify() names every
result whose pickle is no longer the same (CHECK_BATCH_VERIFY=1 turns it on, as
tests/test_check_batch.py does; the worker then names them in its reply, Worker.run() raises
tools/check_batch.py's KeptTableChanged, and tools/c_objects.py stops its run without storing
that check's result).
"""
import functools
import os
import pickle

_ON = False
_VERIFY = False
_KEPT = {}
_SNAPSHOTS = {}


def enable(verify=False):
    global _ON, _VERIFY
    _ON, _VERIFY = True, verify


def disable():
    """Back to reading every time, and forget everything kept (tests)."""
    global _ON, _VERIFY
    _ON = _VERIFY = False
    _KEPT.clear()
    _SNAPSHOTS.clear()


def enabled():
    return _ON


def _frozen(x):
    """A hashable form of an argument: a targets.Target by its name, lists and tuples item by item."""
    if isinstance(x, (list, tuple)):
        return (type(x).__name__,) + tuple(_frozen(i) for i in x)
    if hasattr(x, "units") and hasattr(x, "name"):          # a targets.Target: one per name
        return ("target", x.name)
    hash(x)
    return x


def kept(target=False):
    """Mark a loader whose result may be kept in a worker (see the module docstring)."""
    def wrap(fn):
        @functools.wraps(fn)
        def call(*args, **kwargs):
            if not _ON:
                return fn(*args, **kwargs)
            import version
            key = (fn.__module__, fn.__qualname__, _frozen(args), _frozen(sorted(kwargs.items())), version.V,
                   os.environ.get("UYA_TARGET") if target else None)
            if key not in _KEPT:
                value = fn(*args, **kwargs)
                _KEPT[key] = value
                if _VERIFY:
                    _SNAPSHOTS[key] = pickle.dumps(value, protocol=pickle.HIGHEST_PROTOCOL)
            return _KEPT[key]
        call.uncached = fn
        return call
    return wrap


def verify():
    """The keys of kept results that are no longer what their loader returned (verify mode)."""
    if not _VERIFY:
        return []
    return ["%s.%s%r" % (k[0], k[1], k[2][1:]) for k, blob in _SNAPSHOTS.items()
            if pickle.dumps(_KEPT[k], protocol=pickle.HIGHEST_PROTOCOL) != blob]
