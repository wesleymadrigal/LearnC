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

	def get_life(self):
		return self._life

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
		if monster._life > damage:
			monster._life -= damage
			print "{0} attacked {1} and dealt {2} damage!".format(self._name, monster._name, damage)
			monster.grunt()
		else:
			print "{0} attacked and killed the {1}!!!!".format(self._name, monster._name)
			monster.die()
	def attack_response(self):
		print "Ow, that hurt!"

	def die(self):
		print "%s is dead." % self._name


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
		if human._life > damage:
			human._life -= damage
			print "{0} bit {1} and dealt {2} damage!".format(self._name, human.get_name(), damage)
			human.attack_response()
		else:
			print "{0} bit and killed {1}".format(self._name, human.get_name())
			human.die()

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

	def get_location(self):
		if self._room != None:
			return self._room._location, self._room._room
		else:
			return None

	def die(self):
		self._life = 0
		print "%s is dead" % self._name





















	
