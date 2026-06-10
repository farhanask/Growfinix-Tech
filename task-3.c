# File Organizer using Python
import os
import shutil
from tkinter import Tk, filedialog
# File categories
file_types = {
    "Images": [".jpg", ".jpeg", ".png", ".gif"],
    "Documents": [".pdf", ".docx", ".txt"],
    "Videos": [".mp4", ".mkv"],
    "Music": [".mp3", ".wav"],
    "Programs": [".py", ".c", ".cpp", ".java"]
}
# Select folder using Tkinter
root = Tk()
root.withdraw()
folder_path = filedialog.askdirectory(title="Select Folder")
if folder_path == "":
    print("No folder selected")
    exit()
# Function to organize files
def organize_files(folder):
    for file in os.listdir(folder):
        file_path = os.path.join(folder, file)
        # Skip folders
        if os.path.isdir(file_path):
            continue
        file_ext = os.path.splitext(file)[1].lower()
        moved = False
        for folder_name, extensions in file_types.items():
            if file_ext in extensions:
                target_folder = os.path.join(folder, folder_name)
                # Create folder if not exists
                os.makedirs(target_folder, exist_ok=True)
                target_path = os.path.join(target_folder, file)
                # Avoid duplicate filenames
                count = 1
                filename, extension = os.path.splitext(file)
                while os.path.exists(target_path):
                    new_name = f"{filename}_{count}{extension}"
                    target_path = os.path.join(target_folder, new_name)
                    count += 1
                shutil.move(file_path, target_path)
                print(f"Moved: {file} → {folder_name}")
                moved = True
                break
        # Unknown files
        if not moved:
            unknown_folder = os.path.join(folder, "Others")
            os.makedirs(unknown_folder, exist_ok=True)

            shutil.move(file_path,
                        os.path.join(unknown_folder, file))

            print(f"Moved: {file} → Others")
# Run organizer
organize_files(folder_path)

print("Files organized successfully!")