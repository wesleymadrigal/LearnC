#!/usr/bin/env python
import sys


class Person(object):
	def __init__(self, name):
		self._name = name
		self._alive = True
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
			if room in self._room._access:
				print "Moved from %s to %s" % (self._room._room, room._room)
				self._room._person = None
				self._room = room
				room._person = self
			else:
				print "Cannot access %s from %s" % (room._room, self._room._room)
				print "Here are your options: "
				for room in self._room._access:
					print room._room
		else:
			print "Moved into %s" % room._room
			self._room = room
			room._person = self

	def attack(self, monster, damage):
		if monster._alive:
			if self.get_location() == monster.get_location():
				if monster._life > damage:
					monster._life -= damage
					print "{0} attacked {1} and dealt {2} damage!".format(self._name, monster._name, damage)
					monster.grunt()
				else:
					print "{0} attacked and killed the {1}!!!!".format(self._name, monster._name)
					monster.die()
			else:
				print "You are not in the same room as {0}. {0} is in {1}".format(monster.get_name(), monster.get_location())
		else:
			print "%s is already dead." % monster._name

	def attack_response(self):
		print "Ow, that hurt!"

	def die(self):
		self._alive = False
		self._life = 0
		print "%s is dead." % self._name


class Room(object):
	def __init__(self, room):
		self._room = room
		self._access = []
		self._monster = None
		self._person = None

	def add_room(self, room):
		self._access.append(room)	

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
	def __init__(self, name):
		self._name = name
		self._alive = True
		self._life = 50
		self._power = 50
		self._room = None
	def attack(self, human, damage):
		if human.get_location() == self.get_location():
			if human._life > damage:
				human._life -= damage
				print "{0} bit {1} and dealt {2} damage!".format(self._name, human.get_name(), damage)
				human.attack_response()
			else:
				print "{0} bit and killed {1}".format(self._name, human.get_name())
				human.die()
		else:
			print "{0} is in {1} and you are in {2}, can't attack.".foramt(human.get_name(), human.get_location(), self.get_location())

	def get_name(self):
		return self._name

	def get_life(self):
		return self._life
	
	def grunt(self):
		print "Arghhhhhhhhhhhh!!! Rawrrrr!  I will eat you!"

	def move(self, room):
		if self._room != None:
			if room in self._room._access:
				self._room._monster = None
				print "{0} moved from {1} to {2}".format(self.get_name(), self.get_location(), room._room)
				self._room = room
				room._monster = self
			else:
				print "Cannot move to %s from %s" % (room._room, self._room._room)
				print "Here are your options: "
				for room in self._room._access:
					print room._room
		else:
			self._room = room
			room._monster = self
			print "{0} moved to {1}".format(self.get_name(), self.get_location())

	def get_location(self):
		if self._room != None:
			return self._room._room
		else:
			return "Not in  room"

	def die(self):
		self._life = 0
		self._alive = False
		print "%s is dead" % self._name




class Lesser_Monster(Monster):
	def __init__(self, name):
		self._name = name
		self._alive = True
		self._life = 20
		self._power = 20
		self._room = None
















	
