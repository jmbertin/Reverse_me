import os

SOURCE_PATH = "./level1"
PATCHED_PATH = "level1_patched"

PATCHES = {
    0x1241: b"\x90\x90\x90\x90\x90\x90\x90\x90\x90",
}

def apply_patch(data, offset, patch):
    print(f"[*] Patching at 0x{offset:04x} ({len(patch)} bytes) [0x{patch.hex()}]")
    return data[:offset] + patch + data[offset+len(patch):]

def main():
    if not os.path.exists(SOURCE_PATH):
        print(f"Error: Could not find {SOURCE_PATH}")
        return

    with open(SOURCE_PATH, "rb") as f:
        data = f.read()

    for offset, patch in PATCHES.items():
        data = apply_patch(data, offset, patch)

    with open(PATCHED_PATH, "wb") as f:
        f.write(data)

    os.chmod(PATCHED_PATH, 0o755)
    print(f"[+] Patched binary saved to {PATCHED_PATH}")

if __name__ == "__main__":
    main()
