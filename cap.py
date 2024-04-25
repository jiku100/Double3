import cv2

cap = cv2.VideoCapture(9)

w = int(round(cap.get(cv2.CAP_PROP_FRAME_WIDTH)))
h = int(round(cap.get(cv2.CAP_PROP_FRAME_HEIGHT)))
fps = cap.get(cv2.CAP_PROP_FPS)
fourcc = cv2.VideoWriter_fourcc(*"avc1")
delay = int(round(1000/fps))
out = cv2.VideoWriter('output.mp4', fourcc, fps, (w, h))

elapsed = 0;

while True:
    if elapsed >= 3000:
        break

    ret, frame = cap.read()
    if not ret:
        break

    out.write(frame)
    cv2.waitKey(delay)
    elapsed += delay
cap.release()
out.release()
