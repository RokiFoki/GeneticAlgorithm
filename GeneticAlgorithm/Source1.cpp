// HashCode.cpp : Defines the entry point for the console application.
//

#include <set>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int V; //broj videa
int E; //broj endopointa
int R; //broj requestova
int C; //broj cache servera
int X; //kapacitet cache servera
long long velicinaVidea[10011];
long long zarada[1001][10001];

//za loop
bool update[10011];
set < pair<long long, pair<int, int> > > prioriteti;

typedef struct Endpoint
{
	long long LD; //latencija do data centra

	int K; //broj cache s kojima je spojen endpoint
	vector<int> id; //lista id-eva cache servera
	vector<long long> latency; //lista latencija do cache servera
	int reverseLookup[1011]; //lista za obrnuti lookup
} Endpoint;
Endpoint endpointovi[1011];

typedef struct Request
{
	int video; //koji video se gleda
	int endpoint; //koji endpoint ga gleda
	long long kolicina; //koliko puta ga gleda
} Request;
Request requestovi[1000011];

typedef struct Cache
{
	long long kapacitet;
	vector<int> lista;
} Cache;
Cache cachevi[1011];

int main()
{
	ios::sync_with_stdio(false);

	cin >> V >> E >> R >> C >> X;

	//setupaj kapacitete
	for (int i = 0; i != C; i++)
		cachevi[i].kapacitet = X;

	//velicine
	for (int i = 0; i != V; i++)
		cin >> velicinaVidea[i];

	//enpointovi
	for (int i = 0; i != E; i++)
	{
		cin >> endpointovi[i].LD;
		cin >> endpointovi[i].K;

		for (int j = 0; j != C; j++)
			endpointovi[i].reverseLookup[j] = -1;

		for (int j = 0; j != endpointovi[i].K; j++)
		{
			int id;
			cin >> id;
			endpointovi[i].id.push_back(id);

			int latency;
			cin >> latency;
			endpointovi[i].latency.push_back(latency);

			endpointovi[i].reverseLookup[id] = j;
		}
	}

	//requestovi
	for (int i = 0; i != R; i++)
	{
		cin >> requestovi[i].video;
		cin >> requestovi[i].endpoint;
		cin >> requestovi[i].kolicina;

		if (i % 1000 == 0)
			cerr << i << "/" << R << endl;
		//racunamo zaradu odma
		for (int j = 0; j != endpointovi[requestovi[i].endpoint].K; j++)
			zarada[endpointovi[requestovi[i].endpoint].id[j]][requestovi[i].video] += requestovi[i].kolicina * (endpointovi[requestovi[i].endpoint].LD - endpointovi[requestovi[i].endpoint].latency[j]);
		//po ispisu je oke bilo
	}

	//utrpaj u listu prioriteti
	for (int i = 0; i != C; i++)
	{
		for (int j = 0; j != V; j++)
		{
			if (zarada[i][j] != 0)
				prioriteti.insert(make_pair(zarada[i][j], make_pair(i, j)));
		}
	}

	//idi po listi i radi poso
	int brojac = 1;
	int brojUpdateova = 0;
	for (auto it = prioriteti.rbegin(); it != prioriteti.rend(); it++)
	{
		if (brojac % 1000 == 0)
			cerr << brojac << "/" << prioriteti.size() << endl;
		brojac++;
		int cache = it->second.first;
		int video = it->second.second;

		if (velicinaVidea[video] <= cachevi[cache].kapacitet)
		{
			if (!update[video])
			{
				cachevi[cache].kapacitet -= velicinaVidea[video];
				cachevi[cache].lista.push_back(video);

				update[video] = true;
				brojUpdateova++;
			}

			if (brojUpdateova == 2)
			{
				for (int k = 0; k != V; k++)
					update[k] = false;
			}
		}
	}



	//ispis
	cout << C << endl;
	for (int i = 0; i != C; i++)
	{
		cout << i << " ";
		for (int j = 0; j != cachevi[i].lista.size(); j++)
			cout << cachevi[i].lista[j] << " ";
		cout << endl;
	}

	return 0;
}

