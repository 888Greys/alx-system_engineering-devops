#!/usr/bin/python3
'''
    This module contains the function number_of_subscribers.
'''
import requests
from sys import argv


def number_of_subscribers(subreddit):
    '''
        Returns the number of subscribers for a given subreddit.
    '''
    user_agent = {'User-Agent': 'Lizzie'}
    url = f'https://www.reddit.com/r/{subreddit}/about.json'

    try:
        response = requests.get(url, headers=user_agent)
        response.raise_for_status()  # Raises an HTTPError for bad responses
        data = response.json().get('data', {})
        subscribers = data.get('subscribers', 0)
        print(f'Number of subscribers{subreddit} is: {subscribers}')
    except requests.RequestException as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    if len(argv) != 2:
        print("Usage: python script_name.py <subreddit>")
    else:
        number_of_subscribers(argv[1])
