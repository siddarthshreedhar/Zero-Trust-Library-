# Zero Trust Security Module for NS-3

This repository provides a Zero Trust security module for NS-3, enabling enhanced network simulation security with authentication, access control, encryption, and trust-based decision-making.

## Installation Instructions

### Step 1: Install NS-3
```bash
# Download and build NS-3 (e.g., ns-allinone-3.44)
cd ns-allinone-3.44
```

### Step 2: Install Cryptopp
```bash
# Clone the Cryptopp repository
git clone https://github.com/weidai11/cryptopp

# Navigate to the Cryptopp directory
cd cryptopp

# Build Cryptopp
make
make test
sudo make install
# Return to the NS-3 root directory
cd ..
```

Update `scratch/CMakeLists.txt`:
```cmake
set(target_prefix scratch_)
link_directories(/path/to/ns-allinone-3.44/cryptopp)
```

# Add cryptopp to libraries to link

```
LIBRARIES_TO_LINK "${ns3-libs};${ns3-contrib-libs};cryptopp;"
```

# Build again
```
./build.py --enable-examples --enable-tests
```

### Step 3: Install the Zero Trust Module
```bash
# Navigate to the contrib directory
cd ns-3.44/contrib

# Create a directory for the module
mkdir zero-trust

# Copy the Zero Trust module files into contrib/zero-trust

git clone https://github.com/arun-dot-com/zero-trust.git
```

# Verify the contents
```bash
cd contrib/zero-trust

ls -lth 
```

### Step 4: Build NS-3 with Zero Trust Module
```bash
# Navigate to the NS-3 root directory
cd ../..

# Configure and build NS-3
./ns3 configure --enable-examples --enable-tests

# Ensure zero-trust appears in the list of modules to be built

```

### Step 5: Running Examples
```bash
# Copy example scripts from contrib/zero-trust/examples to scratch
# Execute them using NS-3
./ns3 run scratch/script_name.cc
```

## Notes
- Ensure all dependencies for NS-3 are installed.
- If issues arise, verify the Cryptopp installation path in `CMakeLists.txt`.

## License
This module is provided under an open-source license. See the LICENSE file for details. (to be updated)

