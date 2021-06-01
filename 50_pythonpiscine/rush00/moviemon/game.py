import pickle
import requests
from bs4 import BeautifulSoup
import random


class SettingData:
    def __init__(self):
        self.size = 10
        self.coord_x = int(self.size / 2)
        self.coord_y = int(self.size / 2)
        self.move_dir = 's'
        self.movie_db = self.get_movie_db()

    def get_movie_db(self):
        link_lst = [
            'tt7349950',
            'tt0803096',
            'tt3065204',
            'tt0072271',
            'tt0811073',
            'tt0412467',
            'tt0077533',
            'tt0387564',
            'tt8772262',
            'tt3099498',
            'tt7670212',
            'tt1591095',
            'tt0903747',
            'tt0944947',
            'tt0111161',
            'tt7366338',
            'tt0068646',
            'tt0078935',
            'tt0074486',
            'tt10888594',
            'tt10886166',
            'tt5884052',
            'tt0130623',
            'tt3261302',
            'tt1762399',
            'tt2293640',
            'tt0457400',
            'tt0243462',
            'tt12906778',
            'tt9314862',
            'tt8941294',
            'tt10122486',
            'tt12549474',
        ]
        movie_db = []
        for link in link_lst:
            link = 'https://www.imdb.com/title/' + link
            result = requests.get(link)
            if result.status_code == 200:
                soup = BeautifulSoup(result.text, 'html.parser')
                soup = soup.find('main', {'role': 'main'}).find('section', {'class': 'ipc-page-section'})
                titleblock = soup.find('div')
                peopleblock = soup.find('ul', {'class': 'ipc-metadata-list'}).find_all('ul')

                title = titleblock.find('h1').string
                year = titleblock.find('ul').find('li').find('span').string
                rate = titleblock.find('div', {'class': 'ipc-button__text'}).find('span').string
                poster = soup.find('div', {'class': 'ipc-poster'}).find('img', {'class': 'ipc-image'})['src']
                synopsis = soup.find('p', {'data-testid': 'plot'}).find('div').string
                director = ', '.join([elem.string for elem in peopleblock[0].find_all('a')])
                actor = ', '.join([elem.string for elem in peopleblock[2].find_all('a')])
                movie_db.append({
                    'id': link.strip("'"),
                    'title': title,
                    'year': year,
                    'rate': rate,
                    'poster': poster,
                    'synopsis': synopsis,
                    'director': director,
                    'actor': actor,
                })
        return movie_db


class GameData:
    def __init__(self):
        self.size = 10
        self.coord_x = int(self.size / 2)
        self.coord_y = int(self.size / 2)
        self.move_dir = 's'
        self.ball = 0
        self.strength = 0
        self.catched_movie = []
        self.movie_db = []

    def load(self, filename):
        try:
            with open(filename, 'wb') as f:
                load_data = pickle.load(f)
                self.size = load_data.size
                self.coord_x = load_data.coord_x
                self.coord_y = load_data.coord_y
                self.move_dir = load_data.move_dir
                self.ball = load_data.ball
                self.strength = load_data.strength
                self.catched_movie = load_data.catched_movie
                self.movie_db = load_data.movie_db
                return self
        except Exception:
            return None

    def dump(self, filename):
        with open(filename, 'rb') as f:
            pickle.dump(self, f)
        return self

    def get_random_movie(self):
        shuffled_db = random.shuffle(self.movie_db)
        for movie in shuffled_db:
            if movie['id'] not in self.catched_movie:
                return movie
        return None

    def load_default_settings(self, SettingData):
        self.size = SettingData.size
        self.coord_x = SettingData.coord_x
        self.coord_y = SettingData.coord_y
        self.move_dir = SettingData.move_dir
        self.movie_db = SettingData.movie_db
        return self

    def get_strength(self):
        return len(self.catched_movie)

    def get_movie(self, moviemon_name):
        for movie in self.movie_db:
            if movie['id'] == moviemon_name:
                return movie
        return None
