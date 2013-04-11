#!/usr/bin/env python
import sys


class Person(object):
	def __init__(self):
		self._name = 'Character'
		self._life = 100
		self._power = 100
		self._room = None

	def get_name(self):
		return self._name

	def get_location(self):
		if self._room != None:
			return self._room._room
		else:
			return "You are not in a room"
	def move(self, room):
		if self._room != None:
			print "Moved from %s to %s" % (self._room._room, room._room)
			self._room._person = None
			self._room = room
			room._person = self
		else:
			print "Moved into %s" % room._room
			self._room = room
			room._person = self

	def attack(self, monster, damage):
		monster._life -= damage
		monster.grunt()
	def attack_response(self):
		print "Ow, that hurt!"


class Room(object):
	def __init__(self, location, room):
		self._location = location
		self._room = room
		self._monster = None
		self._person = None
	

	def has_person(self):
		if self._person != None:
			return True
		else:
			return False

	def has_monster(self):
		if self._monster != None:
			return True
		else:
			return False




class Monster(object):
	def __init__(self):
		self._name = 'Ugly Monster'
		self._life = 50
		self._power = 50
		self._room = None
	def attack(self, human, damage):
		human._life -= damage
		human.attack_response()

	def grunt(self):
		print "Arghhhhhhhhhhhh!!! Rawrrrr!  I will eat you!"

	def set_room(self, room):
		if self._room != None:
			self._room._monster = None
			self._room = room
			room._monster = self
		else:
			self._room = room
			room._monster = self






















	
