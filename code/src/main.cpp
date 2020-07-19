#include <opencv2/opencv.hpp>
#include<fstream>
#include<vector>
#include<iterator>
#include<queue>
using namespace cv;
using namespace std;



/*Class that stores information of a pixel*/
class Pixcell
{
public:
	int rowindex;
	int colindex;
	int intensity;
	void setPixcell(int c, int i)
	{
		colindex = c;
		intensity = i;
	}
	int getrow()
	{
		return rowindex;
	}
	int getcol()
	{
		return colindex;
	}
	int getintensity()
	{
		return intensity;
	}
	Pixcell()
	{

	}
	Pixcell(int c, int i)
	{

		colindex = c;
		intensity = i;
	}
	Pixcell(int r, int c, int i)
	{
		rowindex = r;
		colindex = c;
		intensity = i;
	}
};

/*Mapping from image Index to Data Structure Index*/
int imageToGraph(int N, int i, int j)
{
	return 1 + N * i + j;
}
/*Method that adds edge to the graph*/
void addEdge(vector <vector <Pixcell> > &pixGraph, int r, int c, int intensity)
{
	vector <Pixcell> &vec = pixGraph.at(r);
	Pixcell p1(r, c, intensity);
	vec.push_back(p1);
}


/*Method that compares each pixel with adjacent pixels and assigns intensity/weight to the graph*/
void buildPixGraph(vector <vector <Pixcell> > &pixGraph, Mat &image, int height, int width)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == (height - 1))
			{
				if (j == (width - 1))
				{
					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i, j - 1))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j - 1), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j - 1), 1);
					}

					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i - 1, j))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i - 1, j), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i - 1, j), 1);
					}
				}
				else if (j == 0)
				{
					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i, j + 1))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j + 1), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j + 1), 1);
					}

					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i - 1, j))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i - 1, j), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i - 1, j), 1);
					}
				}
				else
				{
					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i, j - 1))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j - 1), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j - 1), 1);
					}

					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i, j + 1))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j + 1), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j + 1), 1);
					}
					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i - 1, j))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i - 1, j), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i - 1, j), 1);
					}

				}
			}
			else if (i == 0)
			{
				if (j == (width - 1))
				{
					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i, j - 1))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j - 1), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j - 1), 1);
					}

					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i + 1, j))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i + 1, j), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i + 1, j), 1);
					}
				}
				else if (j == 0)
				{
					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i, j + 1))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j + 1), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j + 1), 1);
					}

					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i + 1, j))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i + 1, j), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i + 1, j), 1);
					}

				}
				else
				{
					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i, j - 1))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j - 1), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j - 1), 1);
					}

					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i, j + 1))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j + 1), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j + 1), 1);
					}
					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i + 1, j))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i + 1, j), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i + 1, j), 1);
					}
				}
			}
			else
			{
				if (j == (width - 1))
				{
					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i, j - 1))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j - 1), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j - 1), 1);
					}

					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i + 1, j))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i + 1, j), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i + 1, j), 1);
					}
					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i - 1, j))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i - 1, j), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i - 1, j), 1);
					}
				}
				else if (j == 0)
				{
					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i, j + 1))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j + 1), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j + 1), 1);
					}

					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i + 1, j))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i + 1, j), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i + 1, j), 1);
					}
					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i - 1, j))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i - 1, j), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i - 1, j), 1);
					}

				}
				else
				{
					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i, j - 1))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j - 1), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j - 1), 1);
					}

					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i, j + 1))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j + 1), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i, j + 1), 1);
					}
					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i + 1, j))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i + 1, j), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i + 1, j), 1);
					}
					if ((int)image.at<uchar>(i, j) == (int)image.at<uchar>(i - 1, j))
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i - 1, j), 1000000);
					}
					else
					{
						addEdge(pixGraph, imageToGraph(width, i, j), imageToGraph(width, i - 1, j), 1);
					}
				}
			}
		}
	}
}
/*Get intensity / weight of an edge*/
int edgeIntensity(vector<vector<Pixcell> > &graph, int r, int c)
{
	vector<Pixcell> &vec = graph.at(r);
	for (int j = 0; j < vec.size(); j++)
	{

		if (vec.at(j).colindex == c)
		{
			return vec.at(j).intensity;
		}
	}
	return 0;
}

/*Performs BFS */
bool BFS(vector<vector<Pixcell> > &dup_graph, int source, int sink, int *path, int V)
{
	bool *visited = new bool[V]();
	queue<int> queue;
	queue.push(source);
	visited[source] = true;
	int first;
	path[source] = -1;
	while (!queue.empty())
	{
		first = queue.front();
		queue.pop();
		vector<Pixcell> vt = dup_graph.at(first);
		for (int j = 0; j < vt.size(); j++)
		{
			Pixcell pt = vt.at(j);
			if (!visited[pt.colindex] && edgeIntensity(dup_graph, first, pt.colindex) > 0)
			{
				queue.push(pt.colindex);
				path[pt.colindex] = first;
				visited[pt.colindex] = true;
			}

		}
		if (visited[sink])
			break;

	}
	return visited[sink];
}
/*Performs BFS to get the seperated groups of pixels*/
void BFSComp(vector<vector<Pixcell> > &dup_graph, int source, bool *visited, int V)
{
	queue<int> queue;
	queue.push(source);
	visited[source] = true;
	int front;
	while (!queue.empty())
	{
		front = queue.front();
		queue.pop();
		vector<Pixcell> vt1 = dup_graph.at(front);
		for (int j = 0; j < vt1.size(); j++)
		{
			Pixcell pt = vt1.at(j);
			if (!visited[pt.colindex] && edgeIntensity(dup_graph, front, pt.colindex) > 0)
			{
				queue.push(pt.colindex);
				visited[pt.colindex] = true;
			}

		}

	}
}
/*A  Method to modify edge intensity / weight */
void edgeModify(vector<vector<Pixcell> > &graph, int i, int j, int newintensity)
{
	vector<Pixcell> &vec = graph.at(i);
	for (int k = 0; k < vec.size(); k++)
	{
		Pixcell &ptemp1 = vec.at(k);
		if (ptemp1.colindex == j)
		{
			vec.at(k) = Pixcell(i, j, newintensity);
		}
	}
}

/*A method that plots the segmented pixel on the output image*/
void image_plot(Mat &out_image, bool *visited, int V)
{
	Vec3b bgPixels, fgpixels;
	bgPixels[0] = 0;
	bgPixels[1] = 0;
	bgPixels[2] = 0;

	fgpixels[0] = 255;
	fgpixels[1] = 255;
	fgpixels[2] = 255;
	int a, b;
	for (int k = 0; k < V; k++)
	{
		if (visited[k] == true)
		{
			out_image.at<Vec3b>((k - 1) / out_image.cols, (k - 1) % out_image.cols) = bgPixels;
		}
		else
		{
			out_image.at<Vec3b>((k - 1) / out_image.cols, (k - 1) % out_image.cols) = fgpixels;
		}
	}
}

/* A Method that finds the Min-Cut in the graph using source and sink*/
void getMinCut(vector<vector<Pixcell> > &graph, int source, int sink, Mat &out_i, int ver)
{

	int *parent = new int[ver];
	vector<vector<Pixcell> > dup_graph(graph);
	while (BFS(dup_graph, source, sink, parent, ver))
	{
		int i = sink, minIntensity = INT_MAX;
		while (i != source)
		{
			//cout << parent[i];
			minIntensity = min(minIntensity, edgeIntensity(graph, parent[i], i));
			i = parent[i];
		}
		int fi = sink;
		int a = 0, b = minIntensity;
		while (fi != source)
		{
			a = edgeIntensity(dup_graph, parent[fi], fi);
			edgeModify(dup_graph, parent[fi], fi, a - b);
			a = edgeIntensity(dup_graph, fi, parent[fi]);
			edgeModify(dup_graph, fi, parent[fi], a + b);
			fi = parent[fi];
		}
	}

	bool *visited = new bool[ver]();
	BFSComp(dup_graph, source, visited, ver);
	image_plot(out_i, visited, ver);
	delete parent;
	delete visited;
}


int main(int argc, char** argv)
{
	if (argc != 4) {
		cout << "Usage: ../seg input_image initialization_file output_mask" << endl;
		return -1;
	}

	// Load the input image
	// the image should be a 3 channel image by default but we will double check that in teh seam_carving
	Mat in_image;
	in_image = imread(argv[1]/*, CV_LOAD_IMAGE_COLOR*/);

	if (!in_image.data)
	{
		cout << "Could not load input image!!!" << endl;
		return -1;
	}

	if (in_image.channels() != 3) {
		cout << "Image does not have 3 channels!!! " << in_image.depth() << endl;
		return -1;
	}


	// the output image
	Mat out_image = in_image.clone();

	ifstream f(argv[2]);
	if (!f) {
		cout << "Could not load initial mask file!!!" << endl;
		return -1;
	}

	int width = in_image.cols;
	int height = in_image.rows;


	int n;
	f >> n;

	// get the initil pixels
	vector<pair<int, int> > fPix;
	vector<pair<int, int> > bPix;
	for (int i = 0; i < n; ++i) {
		int x, y, t;
		f >> x >> y >> t;

		if (x < 0 || x >= width || y < 0 || y >= height) {
			cout << "I valid pixel mask!" << endl;
			return -1;
		}
		if (t == 1)
		{
			fPix.push_back(make_pair(x, y));
		}
		else
		{
			bPix.push_back(make_pair(x, y));
		}

	}


	int graphVert = (width*height) + 2;

	//A data structure to store pixels of the image

	vector <vector <Pixcell> > pixGraph(graphVert);
	Mat ctg;
	cvtColor(in_image, ctg, COLOR_BGR2GRAY);


	buildPixGraph(pixGraph, ctg, height, width);

	//plotting the given pixels on the graph
	for (int q = 0; q < fPix.size(); q++)
	{
		int mapingx = fPix.at(q).second*width + fPix.at(q).first + 1;
		addEdge(pixGraph, mapingx, graphVert - 1, 1000000);
	}
	for (int q = 0; q < bPix.size(); q++)
	{
		int mapingy = bPix.at(q).second*width + bPix.at(q).first + 1;
		addEdge(pixGraph, 0, mapingy, 1000000);
	}
	Mat out_i(in_image.rows, in_image.cols, in_image.type());

	getMinCut(pixGraph, 0, graphVert - 1, out_i, graphVert);

	out_image = out_i.clone();
	// write it on disk
	imwrite(argv[3], out_image);

	// also display them both

	namedWindow("Original image", WINDOW_AUTOSIZE);
	namedWindow("Show Marked Pixels", WINDOW_AUTOSIZE);
	imshow("Original image", in_image);
	imshow("Show Marked Pixels", out_image);
	waitKey(0);
	return 0;
}