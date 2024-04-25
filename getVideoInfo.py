import cv2

file_name = "output.mp4"

cap = cv2.VideoCapture(file_name)
w = int(round(cap.get(cv2.CAP_PROP_FRAME_WIDTH)))
h = int(round(cap.get(cv2.CAP_PROP_FRAME_HEIGHT)))
fps = cap.get(cv2.CAP_PROP_FPS)
frame_count = cap.get(cv2.CAP_PROP_FRAME_COUNT)

print("Info: {}".format(file_name))
print("Resolution: {} x {}".format(w, h))
print("FPS: {}".format(fps))
print("Frame count: {}".format(frame_count))
