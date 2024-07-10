import tkinter as tk

# Create the main window
root = tk.Tk()

# Set the title of the window
root.title("Root Graphical Window")

# Set the dimensions of the window (width x height)
root.geometry("400x300")

# Add a label to the window
label = tk.Label(root, text="Hello, World!")
label.pack(pady=100)  # Set padding on y-axis

# Run the main loop to display the window
root.mainloop()
