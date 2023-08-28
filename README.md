# Hajime ~ my first hack!
A basic linux-only cheat for TF2. I created this for educational purposes, don't be an asshole and ruin other people's fun :(
Should?? work on any linux distro, but I've only tested this on my normal system (arch).

## Usage
injecting
```
sudo gdb -ex "attach $(pidof hl2_linux)"  \
  -ex "set \$dlopen = (void*(*)(char*, int)) dlopen" \
  -ex "set \$dlclose = (int(*)(void*)) dlclose" \
  -ex "set \$library = \$dlopen(\"/home/bob/Coding/cheats/mystuff/hajime/bin/hajime.so\", 1)"
```

ejecting // reloading
```
call $dlclose($library)
set $library = $dlopen("/home/bob/Coding/cheats/mystuff/hajime/bin/hajime.so", 1)
```

## Features
- [x] Glow
- [x] 3rd person
- [ ] Autostab
- [ ] Aimbot
