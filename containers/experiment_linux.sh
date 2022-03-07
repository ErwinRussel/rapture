# Experiment 1: 1 user
sudo X :0 &
docker-compose up --scale benchmark=1

# Experiment 2: 2 users
sudo X :1 &
docker-compose up --scale benchmark=2

# Experiment 3: 4 users
sudo X :2 &
sudo X :3 &
docker-compose up --scale benchmark=4

# Experiment 4: 8 users
sudo X :4 & 
sudo X :5 & 
sudo X :6 & 
sudo X :7 &
docker-compose up --scale benchmark=8 