FROM python:3.8-slim-buster

WORKDIR /app

COPY requirements.txt requirements.txt

RUN pip3 install -r requirements.txt

COPY fps_exporter.py fps_exporter.py

EXPOSE 8000/tcp
EXPOSE 8001/tcp

CMD python3 fps_exporter.py