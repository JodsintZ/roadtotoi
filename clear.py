import os

for subdir, dirs, files in os.walk("."):
    for file in files:
        if file.endswith(".tcs") or file.endswith(".bin") or file.endswith(".exe") or file.endswith(".o"):
            os.remove(os.path.join(subdir, file))