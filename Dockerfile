# Time-stamp: <2019-09-07 00:58:21 daniel>

#
# Dockerfile
#

# This is the Docker file associated with example projects
# developed for Digimarc

# Auther: Daniel Mendyke [archadious@gmail.com]
# https://github.com/TaurusEight/digimarc


FROM base/archlinux:latest
ADD . /digimarc
RUN pacman-db-upgrade
RUN pacman -Sy archlinux-keyring --noconfirm && pacman -Syyu --noconfirm
RUN pacman -S --noconfirm gcc boost make
RUN pacman -S valgrind --noconfirm
RUN make -C /digimarc/src clean
RUN make -C /digimarc/src
RUN make -C /digimarc/src test
